#include <stdio.h>
#include <stdbool.h>

int N, T[109]; bool dp[109][100009];

int main() {
	// 入力
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%d", &T[i]);
	}
	
	// 配列の初期化
	int sumT = 0;
	for (i = 1; i <= N; i++) {
		sumT += T[i];
	}
	for (i = 1; i <= sumT; i++) {
		dp[0][i] = false;
	}
	dp[0][0] = true;
	
	// 動的計画法
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= sumT; j++) {
			if (j < T[i]) {
				if (dp[i - 1][j] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
			if (j >= T[i]) {
				if (dp[i - 1][j] == true || dp[i - 1][j - T[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
	
	// 答えを計算して出力
	int answer = (1 << 30);
	for (i = 0; i <= sumT; i++) {
		if (dp[N][i] == true) {
			int cooking_time = (i > sumT - i ? i : sumT - i); // max(i, sumT - i) と同じ
			if (answer > cooking_time) {
				answer = cooking_time;
			}
		}
	}
	printf("%d\n", answer);
	
	return 0;
}