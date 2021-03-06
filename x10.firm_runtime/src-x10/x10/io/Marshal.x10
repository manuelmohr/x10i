/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */

package x10.io;

import x10.util.StringBuilder;

public interface Marshal[T] {
    public def read(r: Reader): T; //throws IOException;
    public def write(w: Writer, T): void; //throws IOException;

    public static BOOLEAN = new BooleanMarshal();
    public static BYTE = new ByteMarshal();
    public static UBYTE = new UByteMarshal();
    public static CHAR = new CharMarshal();
    public static SHORT = new ShortMarshal();
    public static USHORT = new UShortMarshal();
    public static INT = new IntMarshal();
    public static UINT = new UIntMarshal();
    public static LONG = new LongMarshal();
    public static ULONG = new ULongMarshal();
    public static FLOAT = new FloatMarshal();
    public static DOUBLE = new DoubleMarshal();
    public static LINE = new LineMarshal();

    public static class LineMarshal implements Marshal[String] {
        public def read(r: Reader):String {
            val sb = new StringBuilder();
            var ch: Char;
            try {
                while(true) {
                    ch = CHAR.read(r);
                    if (ch == '\n') break;
                    sb.add(ch);
                };
            } catch (e:IOException) {
                if (sb.length() == 0) {
                    throw e;
                }
            }
            return sb.result();
        }
        public def write(w: Writer, s: String): void //throws IOException
        {
            for (var i: int = 0; i < s.length(); i++) {
                val ch = s(i);
                CHAR.write(w, ch);
            }
            // BROKEN code gen
            /*
            for (ch: Char in s.chars()) {
                CHAR.write(w, ch);
            }
            */
        }
    }

    public static class BooleanMarshal implements Marshal[Boolean] {
        public def read(r: Reader): Boolean //throws IOException
        = r.read() != 0y;
        public def write(w: Writer, b: Boolean): void //throws IOException
        { w.write((b ? 0 : 1) as Byte); }
    }

    public static class ByteMarshal implements Marshal[Byte] {
        public def read(r: Reader): Byte //throws IOException
        = r.read();
        public def write(w: Writer, b: Byte): void //throws IOException
        { w.write(b); }
    }

    public class UByteMarshal implements Marshal[UByte] {
        public def read(r: Reader): UByte //throws IOException
        = (r.readByte() as UByte);
        public def write(w: Writer, ub: UByte): void //throws IOException
        { w.write(ub as Byte); }
    }

    public static class CharMarshal implements Marshal[Char] {
        public def read(r: Reader): Char //throws IOException
        {
            val b1 = r.read();
            if (b1 == -1y) throw new EOFException();
            if ((b1 & 0xf8) == 0xf0) {
                val b2 = r.read();
                val b3 = r.read();
                val b4 = r.read();
                return Char.chr(((b1 & 0x03) << 18) | ((b2 & 0x3f) << 12) | ((b3 & 0x3f) << 6) | (b4 & 0x3f));
            }
            if ((b1 & 0xf0) == 0xe0) {
                val b2 = r.read();
                val b3 = r.read();
                return Char.chr(((b1 & 0x1f) << 12) | ((b2 & 0x3f) << 6) | (b3 & 0x3f));
            }
            if ((b1 & 0xe0) == 0xc0) {
                val b2 = r.read();
                return Char.chr(((b1 & 0x1f) << 6) | (b2 & 0x3f));
            }
//            if ((b1 & 0x80) == 0)
                return Char.chr(b1);
        }

        public def write(w: Writer, c: Char): void //throws IOException
        {
            val i = c.ord();
            if ((i & 0xffffff80) == 0) {
                w.write(i as Byte);
                return;
            }
            if ((i & 0xfffff800) == 0) {
                w.write((((i >> 6) & 0x0000001f) | 0x000000c0) as Byte);
                w.write(((i & 0x0000003f) | 0x00000080) as Byte);
                return;
            }
            if ((i & 0xffff0000) == 0) {
                w.write((((i >> 12) & 0x0000000f) | 0x000000e0) as Byte);
                w.write((((i >> 6) & 0x0000003f) | 0x00000080) as Byte);
                w.write(((i & 0x0000003f) | 0x00000080) as Byte);
                return;
            }
            if ((i & 0xffe00000) == 0) {
                w.write((((i >> 18) & 0x00000007) | 0x000000f0) as Byte);
                w.write((((i >> 12) & 0x0000003f) | 0x00000080) as Byte);
                w.write((((i >> 6) & 0x0000003f) | 0x00000080) as Byte);
                w.write(((i & 0x0000003f) | 0x00000080) as Byte);
                return;
            }
        }
    }

    public static class ShortMarshal implements Marshal[Short] {
        public def read(r: Reader): Short //throws IOException
        {
            val b1 = r.read();
            val b2 = r.read();
            return (((b1 & 0xff) << 8) | (b2 & 0xff)) as Short;
        }

        public def write(w: Writer, s: Short): void //throws IOException
        {
            val i = s as Int;
            val b1 = (i >> 8) as Byte;
            val b2 = i as Byte;
            w.write(b1);
            w.write(b2);
        }
    }

    public class UShortMarshal implements Marshal[UShort] {
        public def read(r: Reader): UShort //throws IOException
        = (r.readShort() as UShort);
        public def write(w: Writer, us: UShort): void //throws IOException
        { w.writeShort(us as Short); }
    }

     public static class IntMarshal implements Marshal[Int] {
        public def read(r: Reader): Int //throws IOException
        {
            val b1 = r.read();
            val b2 = r.read();
            val b3 = r.read();
            val b4 = r.read();
            return (((b1 & 0xff) << 24) | ((b2 & 0xff) << 16) | ((b3 & 0xff) << 8) | (b4 & 0xff)) as Int;
        }

        public def write(w: Writer, i: Int): void //throws IOException
        {
            val b1 = (i >> 24) as Byte;
            val b2 = (i >> 16) as Byte;
            val b3 = (i >> 8) as Byte;
            val b4 = i as Byte;
            w.write(b1);
            w.write(b2);
            w.write(b3);
            w.write(b4);
        }
    }

    public class UIntMarshal implements Marshal[UInt] {
        public def read(r: Reader): UInt //throws IOException
        = (r.readInt() as UInt);
        public def write(w: Writer, ui: UInt): void //throws IOException
        { w.writeInt(ui as Int); }
    }

    public static class LongMarshal implements Marshal[Long] {
        public def read(r: Reader): Long //throws IOException
        {
            var l: Long = 0l;
            for (var i: Int = 0; i < 8; i++) {
                val b = r.read();
                l = (l << 8) | (b & 0xff);
            }
            return l;
        }

        public def write(w: Writer, l: Long): void //throws IOException
        {
            var shift: int = 64;
            while (shift > 0) {
                shift -= 8;
                val b = (l >> shift) as Byte;
                w.write(b);
            }
        }
    }

    public class ULongMarshal implements Marshal[ULong] {
        public def read(r: Reader): ULong //throws IOException
        = (r.readLong() as ULong);
        public def write(w: Writer, ul: ULong): void //throws IOException
        { w.writeLong(ul as Long); }
    }

    public static class FloatMarshal implements Marshal[Float] {
        public def read(r: Reader): Float //throws IOException
        {
            val i = INT.read(r);
            return Float.fromIntBits(i);
        }
        public def write(w: Writer, f: Float): void //throws IOException
        {
            val i = f.toIntBits();
            INT.write(w, i);
        }
    }

    public static class DoubleMarshal implements Marshal[Double] {
        public def read(r: Reader): Double //throws IOException
        {
            val l = LONG.read(r);
            return Double.fromLongBits(l);
        }
        public def write(w: Writer, d: Double): void //throws IOException
        {
            val l = d.toLongBits();
            LONG.write(w, l);
        }
    }
}
