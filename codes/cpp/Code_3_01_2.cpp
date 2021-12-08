bool isprime(long long N) {
	// N ‚ğ 2 ˆÈã‚Ì®”‚Æ‚µAN ‚ª‘f”‚Å‚ ‚ê‚Î trueA‘f”‚Å‚È‚¯‚ê‚Î false ‚ğ•Ô‚·
	for (long long i = 2; i * i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}