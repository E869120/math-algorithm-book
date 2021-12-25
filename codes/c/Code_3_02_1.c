#include <stdio.h>

// 正の整数 A と B の最大公約数を返す関数
// GCD は Greatest Common Divisor（最大公約数）の略
long long GCD(long long A, long long B) {
	long long answer = 0;
	long long i;
	for (i = 1; i <= A && i <= B; i++) {
		if (A % i == 0 && B % i == 0) {
			answer = i;
		}
	}
	return answer;
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", GCD(A, B));
	return 0;
}
