#include <stdio.h>

int N; long long A[200009];

int main() {
	// 入力
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	// 答えを求める → 答えの出力
	long long answer = 0;
	for (i = 1; i <= N; i++) {
		answer += A[i] * (-N + 2LL * i - 1LL);
	}
	printf("%lld\n", answer);
	return 0;
}
