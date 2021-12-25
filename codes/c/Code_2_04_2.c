#include <stdio.h>

int main() {
	// 入力
	int N, X, Y;
	scanf("%d%d%d", &N, &X, &Y);
	
	// 答えを求める
	int cnt = 0;
	int i;
	for (i = 1; i <= N; i++) {
		// mod の計算は 2.2 節参照
		if (i % X == 0 || i % Y == 0) {
			cnt += 1;
		}
	}
	
	// 出力
	printf("%d\n", cnt);
	
	return 0;
}
