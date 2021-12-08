// ³‚Ì®” A ‚Æ B ‚ÌÅ‘åŒö–ñ”‚ð•Ô‚·ŠÖ”
// GCD ‚Í Greatest Common DivisoriÅ‘åŒö–ñ”j‚Ì—ª
long long GCD(long long A, long long B) {
	long long Answer = 0;
	for (long long i = 1; i <= min(A, B); i++) {
		if (A % i == 0 && B % i == 0) Answer = i;
	}
	return Answer;
}