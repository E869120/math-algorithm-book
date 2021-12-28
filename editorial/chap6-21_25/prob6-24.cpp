#include <iostream>
#include <algorithm>
using namespace std;

int N; long long X[100009], Y[100009], A, B;

int main() {
	// 入力
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	cin >> A >> B;

	// 交差する回数を数える
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		long long xa = X[i] - A, ya = Y[i] - B;
		long long xb = X[(i + 1) % N] - A, yb = Y[(i + 1) % N] - B;
		if (ya > yb) {
			swap(xa, xb);
			swap(ya, yb);
		}
		if (ya <= 0 && 0 < yb && xa * yb - xb * ya < 0) {
			cnt += 1;
		}
	}

	// 答えを出力
	if (cnt % 2 == 1) cout << "INSIDE" << endl;
	else cout << "OUTSIDE" << endl;

	return 0;
}