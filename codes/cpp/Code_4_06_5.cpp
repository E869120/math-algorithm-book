#include <iostream>
using namespace std;

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
	cin >> X >> Y;

	// 二項係数の分子と分母を求める（手順 1.／手順 2.）
	long long bunshi = 1, bunbo = 1;
	for (int i = 1; i <= X + Y; i++) { bunshi *= i; bunshi %= mod; }
	for (int i = 1; i <= X; i++) { bunbo *= i; bunbo %= mod; }
	for (int i = 1; i <= Y; i++) { bunbo *= i; bunbo %= mod; }

	// 答えを求める（手順 3.）
	cout << Division(bunshi, bunbo, mod) << endl;
	return 0;
}