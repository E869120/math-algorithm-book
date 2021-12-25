#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	char answer[100] = ""; // char 型の配列で文字列を表す
	while (N >= 1) {
		// N % 2 は N を 2 で割った余り（例：N = 13 の場合 1）
		// N / 2 は N を 2 で割った値の整数部分（例：N = 13 の場合 6）
		char next_answer[101];
		if (N % 2 == 0) {
			// next_answer に「"0" と answer をつなげたもの」を代入
			sprintf(next_answer, "0%s", answer);
		}
		if (N % 2 == 1) {
			// next_answer に「"1" と answer をつなげたもの」を代入
			sprintf(next_answer, "1%s", answer);
		}
		strcpy(answer, next_answer);
		N = N / 2;
	}
	printf("%s\n", answer);
	return 0;
}
