#include <stdio.h>

int func(int N) {
	return func(N - 1) * N;
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", func(N));
	return 0;
}
