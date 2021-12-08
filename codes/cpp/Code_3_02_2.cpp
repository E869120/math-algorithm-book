// GCD �� Greatest Common Divisor�i�ő���񐔁j�̗�
long long GCD(long long A, long long B) {
	while (A >= 1 && B >= 1) {
		if (A < B) B = B % A; // A < B �̏ꍇ�A�傫���� B ������������
		else A = A % B; // A >= B �̏ꍇ�A�傫���� A ������������
	}
	if (A >= 1) return A;
	return B;
}