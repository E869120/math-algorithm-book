#include <iostream>
using namespace std;
 
const long long mod = 1000000007;
long long N;
 
long long modpow(long long a, long long b, long long m) {
	// 繰り返し二乗法（p は a^1, a^2, a^4, a^8, ... といった値をとる）
	long long p = a, Answer = 1;
	for (int i = 0; i < 60; i++) {
		if ((b & (1LL << i)) != 0) { Answer *= p; Answer %= m; }
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
	cin >> N;
	
	// 答えの計算
	long long V = modpow(4, N + 1, mod) - 1;
	long long Answer = Division(V, 3, mod);
	
	// 出力
	cout << Answer << endl;
	return 0;
}