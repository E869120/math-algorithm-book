#include <stdio.h>
#include <stdbool.h>

const long long MOD = 1000000000;

typedef struct {
	long long p[2][2];
} matrix;

// 2×2 のゼロ行列 (= [[0, 0], [0, 0]]) を返す
matrix zero_matrix() {
	matrix A;
	A.p[0][0] = 0; A.p[0][1] = 0;
	A.p[1][0] = 0; A.p[1][1] = 0;
	return A;
}

// 2×2 行列の積を返す関数
matrix multiplication(matrix A, matrix B) {
	matrix C = zero_matrix();
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= MOD;
			}
		}
	}
	return C;
}

// 行列 A の n 乗を返す関数
matrix power(matrix A, long long n) {
	matrix P = A;
	matrix Q = zero_matrix();
	bool flag = false;
	for (int i = 0; i < 60; i++) {
		if ((n & (1LL << i)) != 0LL) {
			if (flag == false) {
				Q = P;
				flag = true;
			}
			else {
				Q = multiplication(Q, P);
			}
		}
		P = multiplication(P, P);
	}
	return Q;
}

int main() {
	// 入力 → 累乗の計算（N が 2 以上でなければ正しく動作しないので注意）
	long long N;
	scanf("%lld", &N);
	matrix A; A.p[0][0] = 1; A.p[0][1] = 1; A.p[1][0] = 1; A.p[1][1] = 0;
	matrix B = power(A, N - 1);
	
	// 出力（下から 9 桁目が 0 の場合、最初に 0 を含まない形で出力していることに注意）
	printf("%lld\n", (B.p[1][0] + B.p[1][1]) % MOD);
	
	return 0;
}
