#include <stdio.h>

int cnt = 1000;

int func1() {
	return 2021;
}

int func2(int pos) {
	cnt += 1;
	return cnt + pos;
}

int main() {
	printf("%d\n", func1()); // 「2021」と出力
	printf("%d\n", func2(500)); // 「1501」と出力
	printf("%d\n", func2(500)); // 「1502」と出力
	return 0;
}
