#include <stdio.h>

int main() {
	// 入力
	int N, X;
	scanf("%d%d", &N, &X);

	// すべての (a, b, c) の組み合わせを試す
	int answer = 0;
	int a, b, c;
	for (a = 1; a <= N; a++) {
		for (b = a + 1; b <= N; b++) {
			for (c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// 答えを出力
	printf("%d\n", answer);

	return 0;
}