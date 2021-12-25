#include <stdio.h>

int main() {
	// 入力
	int N; long long X, Y;
	scanf("%d%lld%lld", &N, &X, &Y);

	// 4 つの整数 (a, b, c, d) の全探索 → 答えの出力
	int a, b, c, d;
	for (a = 1; a <= N; a++) {
		for (b = a; b <= N; b++) {
			for (c = b; c <= N; c++) {
				for (d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						printf("Yes\n");
						return 0; // プログラムの実行を終了させる
					}
				}
			}
		}
	}
	printf("No\n"); // 1 つも見つからなかったら No
	return 0;
}
