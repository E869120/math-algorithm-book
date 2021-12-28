#include <iostream>
using namespace std;
 
const long long mod = 998244353;
long long A, B, C;
 
int main() {
	// 入力
	cin >> A >> B >> C;
	
	// 計算
	long long D = A * (A + 1) / 2; D %= mod;
	long long E = B * (B + 1) / 2; E %= mod;
	long long F = C * (C + 1) / 2; F %= mod;
	
	// 答えを出力
	// ここで (D * E * F) % mod にしても、途中で 10^27 を扱う可能性がある
	// そのため、long long 型でもオーバーフローすることに注意！
	cout << (D * E % mod) * F % mod << endl;
	return 0;
}