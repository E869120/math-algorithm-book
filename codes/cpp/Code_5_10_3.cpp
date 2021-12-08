#include <iostream>
using namespace std;

long long N, X, Y;

int main() {
	// 入力
	cin >> N >> X >> Y;

	// 4 つの整数 (a, b, c, d) の全探索 → 答えの出力
	for (int a = 1; a <= N; a++) {
		for (int b = a; b <= N; b++) {
			for (int c = b; c <= N; c++) {
				for (int d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						cout << "Yes" << endl;
						return 0; // プログラムの実行を終了させる
					}
				}
			}
		}
	}
	cout << "No" << endl; // 1 つも見つからなかったら No
	return 0;
}