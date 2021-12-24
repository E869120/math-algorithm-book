#include <iostream>
using namespace std;

struct Matrix {
	long long p[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
};

Matrix Multiplication(Matrix A, Matrix B) { // 3×3 行列 A, B の積を返す関数
	Matrix C;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= 1000000007;
			}
		}
	}
	return C;
}

Matrix Power(Matrix A, long long n) { // A の n 乗を返す関数
	Matrix P = A, Q;
	bool flag = false;
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
	// 入力 → 累乗の計算（N が 2 以上でなければ正しく動作しないので注意）
	long long N;
	cin >> N;
	
	// 行列 A の作成
	Matrix A;
	A.p[0][0] = 1; A.p[0][1] = 1; A.p[0][2] = 1; A.p[1][0] = 1; A.p[2][1] = 1;
	
	// B=A^{N-1} の計算
	Matrix B = Power(A, N - 1);

	// 答えの出力
	cout << (2LL * B.p[2][0] + B.p[2][1] + B.p[2][2]) % 1000000007 << endl;
	return 0;
}