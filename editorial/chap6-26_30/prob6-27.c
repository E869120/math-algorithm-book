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

const long long MOD = 1000000007;
long long fact[200009];

long long ncr(int n, int r) {
	// ncr は n! を r! × (n-r)! で割った値
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD);
}

int main() {
	// 配列の初期化（fact[i] は i の階乗を 1000000007 で割った余り）
	fact[0] = 1;
	int i;
	for (i = 1; i <= 200000; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	// 入力 → 答えを計算して出力
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int answer = 0;
		for (int j = 1; i * (j - 1) < N; j++) {
			answer += ncr(N - (i - 1) * (j - 1), j);
			answer %= MOD;
		}
		printf("%d\n", answer);
	}
	
	return 0;
}