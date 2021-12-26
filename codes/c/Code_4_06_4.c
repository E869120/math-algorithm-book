#include <stdio.h>

long long modpow(long long a, long long b, long long m) {
	// 繰り返し二乗法（p は a^1, a^2, a^4, a^8, ... といった値をとる）
	long long p = a, answer = 1;
	int i;
	for (i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) {
			answer = (answer * p) % m;
		}
		p = (p * p) % m;
	}
	return answer;
}

int main() {
	const long long MOD = 1000000007;
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", modpow(a, b, MOD));
	return 0;
}
