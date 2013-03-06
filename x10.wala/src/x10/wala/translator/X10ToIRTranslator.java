/*
 * Created on Sep 26, 2005
 */
package x10.wala.translator;

import java.io.PrintWriter;

import x10.wala.loader.X10SourceLoaderImpl;
import x10.wala.util.X10CAstPrinter;

import com.ibm.wala.cast.java.translator.Java2IRTranslator;
import com.ibm.wala.cast.tree.CAstEntity;
import com.ibm.wala.classLoader.ModuleEntry;

public class X10ToIRTranslator extends Java2IRTranslator {
	public X10ToIRTranslator(X10SourceLoaderImpl srcLoader) {
		super(srcLoader);
	}

	public void translate(ModuleEntry module, CAstEntity ce) {
		PrintWriter printWriter = new PrintWriter(System.out);

		X10CAstPrinter.printTo(ce, printWriter);
		printWriter.flush();

		new X10CAst2IRTranslator(module, ce, (X10SourceLoaderImpl) fLoader).translate();
	}
}
