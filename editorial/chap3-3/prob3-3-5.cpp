#include <iostream>
using namespace std;

long long N;
long long A[500009];
long long x = 0, y = 0, z = 0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// a, b, c, d の個数を数える
	for (int i = 1; i <= N; i++) {
		if (A[i] == 1) x += 1;
		if (A[i] == 2) y += 1;
		if (A[i] == 3) z += 1;
	}
	
	// 出力
	cout << x * (x - 1) / 2 + y * (y - 1) / 2 + z * (z - 1) / 2 << endl;
	return 0;
}