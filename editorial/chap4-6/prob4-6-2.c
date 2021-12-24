#include <stdio.h>

const long long mod = 1000000007;
int X, Y;

long long modpow(long long a, long long b, long long m) {
	// 繰り返し二乗法（p は a^1, a^2, a^4, a^8, ... といった値をとる）
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

// Division(a, b, m) は a÷b mod m を返す関数
long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// 入力
	scanf("%d%d", &X, &Y);
	
	// 場合分け（a, b が負になってしまう場合）
	if (2 * Y - X < 0 || 2 * X - Y < 0) {
		printf("0\n");
		return 0;
	}
	
	// 場合分け（a, b が整数にならない場合）
	if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
		printf("0\n");
		return 0;
	}
	
	// 二項係数の分子と分母を求める（手順 1.／手順 2.）
	long long bunshi = 1, bunbo = 1;
	long long a = (2 * Y - X) / 3, b = (2 * X - Y) / 3;
	for (int i = 1; i <= a + b; i++) { bunshi *= i; bunshi %= mod; }
	for (int i = 1; i <= a; i++) { bunbo *= i; bunbo %= mod; }
	for (int i = 1; i <= b; i++) { bunbo *= i; bunbo %= mod; }
	
	// 答えを求める（手順 3.）
	printf("%lld\n", Division(bunshi, bunbo, mod));
	return 0;
}