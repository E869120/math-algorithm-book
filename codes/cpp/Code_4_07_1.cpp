#include <iostream>
using namespace std;

struct Matrix {
	long long p[2][2] = { {0, 0}, {0, 0} };
};

Matrix Multiplication(Matrix A, Matrix B) { // 2�~2 �s�� A, B �̐ς�Ԃ��֐�
	Matrix C;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 2; j++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= 1000000000;
			}
		}
	}
	return C;
}

Matrix Power(Matrix A, long long n) { // A �� n ���Ԃ��֐�
	Matrix P = A, Q; bool flag = false;
	for (int i = 0; i < 60; i++) {
		if ((n & (1LL << i)) != 0LL) {
			if (flag == false) { Q = P; flag = true; }
			else { Q = Multiplication(Q, P); }
		}
		P = Multiplication(P, P);
	}
	return Q;
}

int main() {
	// ���� �� �ݏ�̌v�Z�iN �� 2 �ȏ�łȂ���ΐ��������삵�Ȃ��̂Œ��Ӂj
	long long N;
	cin >> N;
	Matrix A; A.p[0][0] = 1; A.p[0][1] = 1; A.p[1][0] = 1;
	Matrix B = Power(A, N - 1);

	// �o�́i������ 9 ���ڂ� 0 �̏ꍇ�A�ŏ��� 0 ���܂܂Ȃ��`�ŏo�͂��Ă��邱�Ƃɒ��Ӂj
	cout << (B.p[1][0] + B.p[1][1]) % 1000000000 << endl;
	return 0;
}