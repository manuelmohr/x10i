package x10firm.visit;

import x10.types.X10ClassType;

/**
 * An interface to trigger the instantiation of generic code.
 * @author matze
 */
public interface GenericCodeInstantiationQueue {
	/** Trigger instantiation of a classtype. */
	void instantiateGenericClass(X10ClassType type);
}
