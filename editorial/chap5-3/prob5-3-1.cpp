#include <iostream>
using namespace std;

int main() {
	// 入力
	long long H, W;
	cin >> H >> W;
	
	// 場合分け
	if (H == 1 || W == 1) {
		cout << "1" << endl;
	}
	else {
		cout << (H * W + 1) / 2 << endl;
	}
	return 0;
}