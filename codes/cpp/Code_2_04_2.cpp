#include <iostream>
using namespace std;

int main() {
	// 入力
	int N, X, Y;
	cin >> N >> X >> Y;

	// 答えを求める
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0 || i % Y == 0) cnt++; // mod の計算は 2.2 節参照
	}

	// 出力
	cout << cnt << endl;
	return 0;
}