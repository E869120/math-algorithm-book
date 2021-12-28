#include <stdio.h>

int N; long long X[100009], Y[100009], A, B;

int main() {
	// 入力
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]);
	}
	scanf("%lld%lld", &A, &B);

	// 交差する回数を数える
	int cnt = 0;
	for (i = 0; i < N; i++) {
		long long xa = X[i] - A, ya = Y[i] - B;
		long long xb = X[(i + 1) % N] - A, yb = Y[(i + 1) % N] - B;
		if (ya > yb) {
			long long tmp1 = xa; xa = xb; xb = tmp1;
			long long tmp2 = ya; ya = yb; yb = tmp2;
		}
		if (ya <= 0 && 0 < yb && xa * yb - xb * ya < 0) {
			cnt += 1;
		}
	}

	// 答えを出力
	if (cnt % 2 == 1) {
		printf("INSIDE\n");
	}
	else {
		printf("OUTSIDE\n");
	}

	return 0;
}