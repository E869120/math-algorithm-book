#include <stdio.h>

const long long mod = 1000000007;
int N; long long A[200009];
long long fact[200009];

long long modpow(long long a, long long b, long long m) {
	// 繰り返し二乗法（p は a^1, a^2, a^4, a^8, ... といった値をとる）
	long long p = a, Answer = 1;
	int i;
	for (i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long ncr(int n, int r) {
	// ncr は n! を r! × (n-r)! で割った値
	return Division(fact[n], fact[r] * fact[n - r] % mod, mod);
}

int main() {
	// 配列の初期化（fact[i] は i の階乗を 1000000007 で割った余り）
	fact[0] = 1;
	int i;
	for (i = 1; i <= 200000; i++) {
		fact[i] = 1LL * i * fact[i - 1] % mod;
	}

	// 入力
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	// 答えを求める
	long long answer = 0;
	for (i = 1; i <= N; i++) {
		answer += A[i] * ncr(N - 1, i - 1);
		answer %= mod;
	}
	
	// 答えの出力
	printf("%lld\n", answer);
	return 0;
}
