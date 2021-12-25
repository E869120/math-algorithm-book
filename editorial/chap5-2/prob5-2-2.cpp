#include <iostream>
using namespace std;
 
int main() {
	// 入力
	long long N;
	cin >> N;
	
	// N = 2^k-1 の形で表されるかどうかを調べる
	bool flag = false;
	for (int k = 1; k <= 60; k++) {
		if (N == (1LL << k) - 1LL) flag = true;
	}
	
	// 出力
	if (flag == true) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}