#include <stdio.h>

int main() {
	long long N;
	scanf("%lld", &N);
	if (N % 4 == 0) {
		printf("Second\n"); // 後手必勝
	}
	else {
		printf("First\n"); // 先手必勝
	}
	return 0;
}
