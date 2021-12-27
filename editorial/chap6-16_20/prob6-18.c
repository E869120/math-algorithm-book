#include <stdio.h>

long long GCD(long long A, long long B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	// 入力
	long long A, B;
	scanf("%lld%lld", &A, &B);

	// 最小公倍数が 10^18 を超えるかどうか判定
	if (A / GCD(A, B) > 1000000000000000000 / B) {
		printf("Large\n");
	}
	else {
		printf("%lld\n", A / GCD(A, B) * B);
	}
	return 0;
}