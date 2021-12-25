#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b) {
	return (a < b ? a : b);
}

int maximum(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	// 入力
	int N, K;
	scanf("%d%d", &N, &K);

	// 事象 B の個数 yojishou を数える
	long long yojishou = 0;
	int a, b, c;
	for (a = 1; a <= N; a++) {
		int l = maximum(a - (K - 1), 1); // b, c の探索範囲の下限 l
		int r = minimum(a + (K - 1), N); // b, c の探索範囲の上限 r
		for (b = l; b <= r; b++) {
			for (c = l; c <= r; c++) {
				if (abs(b - c) <= K - 1) yojishou += 1;
			}
		}
	}
	
	// 答えの出力
	printf("%lld\n", (long long)N * N * N - yojishou);
	return 0;
}
