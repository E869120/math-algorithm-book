bool isprime(long long N) {
	// N を 2 以上の整数とし、N が素数であれば true、素数でなければ false を返す
	for (long long i = 2; i * i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}