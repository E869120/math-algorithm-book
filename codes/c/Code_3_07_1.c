#include <stdio.h>
#include <stdlib.h>

int N, H[100009], dp[100009];

int main() {
	// 入力
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}

	// 動的計画法 → 答えの出力
	for (i = 1; i <= N; i++) {
		if (i == 1) dp[i] = 0;
		if (i == 2) dp[i] = abs(H[i - 1] - H[i]);
		if (i >= 3) {
			int v1 = dp[i - 1] + abs(H[i - 1] - H[i]); // 1 個前の足場からジャンプするとき
			int v2 = dp[i - 2] + abs(H[i - 2] - H[i]); // 2 個前の足場からジャンプするとき
			dp[i] = (v1 < v2 ? v1 : v2); // v1 と v2 のうち小さい方の値
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}
