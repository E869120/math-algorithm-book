#include <stdio.h>

int main() {
	long long N;
	scanf("%lld", &N);
	long long i;
	for (i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		printf("%lld\n", i); // i を約数に追加
		if (i != N / i) {
			printf("%lld\n", N / i); // i ≠ N/i のとき、N/i も約数に追加
		}
	}
	return 0;
}
