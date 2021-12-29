#include <iostream>
using namespace std;

struct matrix {
	double x[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};
};

// 行列の掛け算
matrix multiplication(matrix A, matrix B) {
	matrix C;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				C.x[i][j] += A.x[i][k] * B.x[k][j];
			}
		}
	}
	return C;
}

// 行列の累乗
matrix power(matrix A, int n) {
	matrix P = A, Q;
	bool flag = false;
	for (int i = 0; i < 30; i++) {
		if ((n & (1 << i)) != 0) {
			if (flag == false) { Q = P; flag = true; }
			else Q = multiplication(Q, P);
		}
		P = multiplication(P, P);
	}
	return Q;
}

int main() {
	int Q, T; double X, Y, Z;
	cin >> Q;
	for (int t = 1; t <= Q; t++) {
		// 入力 → 行列 A の構築
		cin >> X >> Y >> Z >> T;
		matrix A;
		A.x[0][0] = 1.0 - X; A.x[2][0] = X;
		A.x[1][1] = 1.0 - Y; A.x[0][1] = Y;
		A.x[2][2] = 1.0 - Z; A.x[1][2] = Z;

		// 行列累乗の計算 → 答えを出力
		matrix B = power(A, T);
		double answerA = B.x[0][0] + B.x[0][1] + B.x[0][2];
		double answerB = B.x[1][0] + B.x[1][1] + B.x[1][2];
		double answerC = B.x[2][0] + B.x[2][1] + B.x[2][2];
		printf("%.12lf %.12lf %.12lf\n", answerA, answerB, answerC);
	}
	return 0;
}