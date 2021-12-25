#include <stdio.h>

// GCD は Greatest Common Divisor（最大公約数）の略
long long GCD(long long A, long long B) {
	while (A >= 1 && B >= 1) {
		if (A < B) B = B % A; // A < B の場合、大きい方 B を書き換える
		else A = A % B; // A >= B の場合、大きい方 A を書き換える
	}
	if (A >= 1) return A;
	return B;
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", GCD(A, B));
	return 0;
}
