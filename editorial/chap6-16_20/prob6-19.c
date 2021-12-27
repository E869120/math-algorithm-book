#include <stdio.h>

int N, B[109];

int main() {
	// 入力
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N - 1; i++) {
		scanf("%d", &B[i]);
	}

	// 数列 A の要素の合計を求める
	int answer = B[1] + B[N - 1];
	for (i = 2; i <= N - 1; i++) {
		answer += (B[i - 1] < B[i] ? B[i - 1] : B[i]);
	}

	// 答えの出力
	printf("%d\n", answer);

	return 0;
}