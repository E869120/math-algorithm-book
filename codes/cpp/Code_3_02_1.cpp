// ���̐��� A �� B �̍ő���񐔂�Ԃ��֐�
// GCD �� Greatest Common Divisor�i�ő���񐔁j�̗�
long long GCD(long long A, long long B) {
	long long Answer = 0;
	for (long long i = 1; i <= min(A, B); i++) {
		if (A % i == 0 && B % i == 0) Answer = i;
	}
	return Answer;
}