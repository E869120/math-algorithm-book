#include <stdio.h>

int func(int N) {
	if (N == 1) {
		return 1; // このような場合分けすべきケースを「ベースケース」といいます
	}
	return func(N - 1) * N;
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", func(N));
	return 0;
}
