#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long fact[100009];

long long modpow(long long a, long long b, long long m) {
	// 繰り返し二乗法（p は a^1, a^2, a^4, a^8, ... といった値をとる）
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
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
	for (int i = 1; i <= 100000; i++) {
		fact[i] = 1LL * i * fact[i - 1] % mod;
	}

	// 入力 → 答えを計算して出力
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int answer = 0;
		for (int j = 1; j <= (N + i - 1) / i; j++) {
			answer += ncr(N - (i - 1) * (j - 1), j);
			answer %= mod;
		}
		cout << answer << endl;
	}
	return 0;
}