#include <string>
#include <iostream>
using namespace std;

// リュカの定理で ncr mod 3 を計算
int ncr(int x, int y) {
	if (x < 3 && y < 3) {
		if (x < y) return 0;
		if (x == 2 && y == 1) return 2;
		return 1;
	}
	return ncr(x / 3, y / 3) * ncr(x % 3, y % 3) % 3;
}

int main() {
	// 入力
	int N; string C;
	cin >> N >> C;
	
	// 答えを求める
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int code = -1;
		if (C[i] == 'B') code = 0;
		if (C[i] == 'W') code = 1;
		if (C[i] == 'R') code = 2;
		answer += code * ncr(N - 1, i);
		answer %= 3;
	}
	
	// 答えを (-1)^(N-1) で掛ける
	if (N % 2 == 0) {
		answer = (3 - answer) % 3;
	}
	
	// 答えを出力（"BWR" の answer 文字目）
	cout << "BWR"[answer] << endl;
	
	return 0;
}