#include <iostream>
using namespace std;
 
const long long mod = 1000000007;
long long N;
 
int main() {
	// 入力
	cin >> N;
	
	// 答えを求める
	long long val = N * (N + 1) / 2;
	val %= 1000000007;
	cout << val * val % mod << endl;
	return 0;
}