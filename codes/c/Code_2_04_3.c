#include <stdio.h>

int main() {
	// 入力
	int N, S;
	scanf("%d%d", &N, &S);
	
	// 答えを求める
	int answer = 0;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i + j <= S) {
				answer += 1;
			}
		}
	}
	
	// 出力
	printf("%d\n", answer);
}
