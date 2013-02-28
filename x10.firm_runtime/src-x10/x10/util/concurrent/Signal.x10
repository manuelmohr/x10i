package x10.util.concurrent;

import x10.io.CustomSerialization;
import x10.io.SerialData;

/**
 * @author mohr
 */
public class Signal {
    public native def this();

    public native def wait(): void;

    public native def signal(): void;

   /**
    * Serialization of Signal objects is forbidden.
    * @throws UnsupportedOperationException
    */
    public def serialize(): SerialData {
        throw new UnsupportedOperationException("Cannot serialize " + typeName());
    }

   /**
    * Deserialization of Signal objects is forbidden.
    * @throws UnsupportedOperationException
    */
    private def this(SerialData) {
        throw new UnsupportedOperationException("Cannot deserialize " + typeName());
    }
}
