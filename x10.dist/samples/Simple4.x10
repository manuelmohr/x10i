class Main {
	public static def fib(n : Int) {
		if (n == 0) return 0;
		return fib(n-1) + fib(n-2);
	}
}
