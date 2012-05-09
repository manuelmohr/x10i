/*
 * This file is part of the Polyglot extensible compiler framework.
 *
 * Copyright (c) 2000-2006 Polyglot project group, Cornell University
 * Copyright (c) 1997-2001 Purdue Research Foundation, Purdue University
 * 
 */

package polyglot.types.reflect;

import polyglot.types.*;
import java.util.*;
import java.io.*;
import java.lang.reflect.Modifier;

/**
 * Method represents a method in a Java classfile.  A method's name and
 * value (the types of its parameters and its return type) are modeled
 * as indices into it class's constant pool.  A method has modifiers 
 * that determine whether it is public, private, static, final, etc.
 * Methods have a number of attributes such as their Code and any
 * Exceptions they may throw.
 *
 * @see polyglot.types.reflect Code
 * @see polyglot.types.reflect Exceptions
 *
 * @author Nate Nystrom
 *         (<a href="mailto:nystrom@cs.purdue.edu">nystrom@cs.purdue.edu</a>)
 */
public class Method
{
  protected ClassFile clazz; 
  protected DataInputStream in;
  
  protected int modifiers;
  protected int name;
  protected int type;
  protected Attribute[] attrs;
  protected Exceptions exceptions;
  protected Signature signature;
  protected boolean synthetic;

  /**
   * Constructor.  Read a method from a class file.
   *
   * @param in
   *        The data stream of the class file.
   * @param clazz
   *        The class file containing the method.
   * @exception IOException
   *        If an error occurs while reading.
   */
  public Method(DataInputStream in, ClassFile clazz) 
  {
    this.clazz = clazz;
    this.in = in;
  }

  private static final int SYNTHETIC = 0x00001000;
  public static boolean isSynthetic(int bits) {
    return (bits & Modifier.VOLATILE) != 0 || (bits & SYNTHETIC) != 0;
  }

  public void initialize() throws IOException {
    modifiers = in.readUnsignedShort();
    if (isSynthetic(modifiers)) {
      synthetic = true;
    }

    name = in.readUnsignedShort();
    type = in.readUnsignedShort();

    int numAttributes = in.readUnsignedShort();

    attrs = new Attribute[numAttributes];

    for (int i = 0; i < numAttributes; i++) {
      int nameIndex = in.readUnsignedShort();
      int length = in.readInt();

      Constant name = clazz.getConstants()[nameIndex];

      if (name != null) {
        if ("Exceptions".equals(name.value())) {
          exceptions = new Exceptions(clazz, in, nameIndex, length);
          attrs[i] = exceptions;
        }
        if ("Synthetic".equals(name.value())) {
          synthetic = true;
        }
        if ("Signature".equals(name.value())) {
          signature = new Signature(clazz, in, nameIndex, length);
          attrs[i] = signature;
        }
      }

      if (attrs[i] == null) {
        long n = in.skip(length);
        if (n != length) {
          throw new EOFException();
        }
      }
    }
  }

  public boolean isSynthetic() {
    return synthetic;
  }
  public Attribute[] getAttrs() {
      return attrs;
  }
  public ClassFile getClazz() {
      return clazz;
  }
  public Exceptions getExceptions() {
      return exceptions;
  }
  public int getModifiers() {
      return modifiers;
  }
  public int getName() {
      return name;
  }
  public int getType() {
      return type;
  }
  public Signature getSignature() {
    return signature;
  }
  public String name() {
    return (String) clazz.getConstants()[this.name].value();
  }
  public String signature() {
    if (this.signature != null) {
      return (String) clazz.getConstants()[this.signature.getSignature()].value();
    }
    return (String) clazz.getConstants()[this.type].value();
  }
  public String toString() {
    return Modifier.toString(modifiers)+"("+Integer.toHexString(modifiers)+") "+name()+signature();
  }
}
