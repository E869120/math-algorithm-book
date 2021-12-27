#include <stdio.h>

int main() {
	// 入力
	long long N;
	scanf("%lld", &N);

	// 縦の長さを 1 から √N まで全探索
	long long answer = (1LL << 60);
	long long x;
	for (x = 1; x * x <= N; x++) {
		if (N % x == 0 && answer > 2 * x + 2 * (N / x)) {
			answer = 2 * x + 2 * (N / x);
		}
	}

	// 答えを出力
	printf("%lld\n", answer);

	return 0;
}