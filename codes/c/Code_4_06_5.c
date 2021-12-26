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

// division(a, b, m) は a÷b mod m を返す関数
long long division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// 入力
	int X, Y;
	scanf("%d%d", &X, &Y);
	
	// 二項係数の分子と分母を求める（手順 1.／手順 2.）
	const long long MOD = 1000000007;
	long long bunshi = 1, bunbo = 1;
	int i;
	for (i = 1; i <= X + Y; i++) {
		bunshi = (bunshi * i) % MOD;
	}
	for (i = 1; i <= X; i++) {
		bunbo = (bunbo * i) % MOD;
	}
	for (i = 1; i <= Y; i++) {
		bunbo = (bunbo * i) % MOD;
	}
	
	// 答えを求める（手順 3.）
	printf("%lld\n", division(bunshi, bunbo, MOD));
	
	return 0;
}
