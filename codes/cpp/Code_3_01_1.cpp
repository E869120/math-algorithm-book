bool isprime(long long N) {
	// N を 2 以上の整数とし、N が素数であれば true、素数でなければ false を返す
	for (long long i = 2; i <= N - 1; i++) {
		// N が i で割り切れた場合、この時点で素数ではないと分かる
		if (N % i == 0) return false;
	}
	return true;
}