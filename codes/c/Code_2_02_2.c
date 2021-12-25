#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b); // a と b を入力する
	printf("%d\n", a & b); // a AND b の値を出力する
	printf("%d\n", a | b); // a OR b の値を出力する
	printf("%d\n", a ^ b); // a XOR b の値を出力する
	return 0;
}
