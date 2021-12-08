long long GCD(long long A, long long B) {
	if (B == 0) return A; // ベースケース
	return GCD(B, A % B);
}