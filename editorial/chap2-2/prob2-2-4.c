#include <stdio.h>

int N, A[109];
int Answer = 0;

int main() {
	// 入力
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	// 答えの計算
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// 出力
	printf("%d\n", Answer % 100);
	return 0;
}
