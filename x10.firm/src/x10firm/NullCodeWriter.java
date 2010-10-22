package x10firm;

import java.io.IOException;

import polyglot.util.CodeWriter;

/**
 * Dummy CodeWriter which do nothing.
 * 
 * @author tux
 * 
 */
public class NullCodeWriter extends CodeWriter {

	@Override
	public void write(String s) {
		// TODO Auto-generated method stub

	}

	@Override
	public void write(String s, int length) {
		// TODO Auto-generated method stub

	}

	@Override
	public void begin(int n) {
		// TODO Auto-generated method stub

	}

	@Override
	public void end() {
		// TODO Auto-generated method stub

	}

	@Override
	public void allowBreak(int n, int level, String alt, int altlen) {
		// TODO Auto-generated method stub

	}

	@Override
	public void unifiedBreak(int n, int level, String alt, int altlen) {
		// TODO Auto-generated method stub

	}

	@Override
	public void newline(int n, int level) {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean flush() throws IOException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void close() throws IOException {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean flush(boolean format) throws IOException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return null;
	}

}
