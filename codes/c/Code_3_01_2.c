#include <stdio.h>
#include <stdbool.h>

// 2 以上の整数 N に対し、N が素数であれば true、素数でなければ false を返す関数
bool isprime(long long N) {
	long long i;
	for (i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long N;
	scanf("%lld", &N);
	if (isprime(N) == true) {
		printf("prime\n");
	}
	else {
		printf("not prime\n");
	}
	return 0;
}
