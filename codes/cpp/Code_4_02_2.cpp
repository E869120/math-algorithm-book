#include <iostream>
using namespace std;

int N, B[100009];
int Q, L[100009], R[100009], X[100009];

int main() {
	// 入力・階差の計算
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> L[i] >> R[i] >> X[i];
		B[L[i]] += X[i];
		B[R[i] + 1] -= X[i];
	}

	// 答えの出力
	for (int i = 2; i <= N; i++) {
		if (B[i] > 0) cout << "<";
		if (B[i] == 0) cout << "=";
		if (B[i] < 0) cout << ">";
	}
	cout << endl;
	return 0;
}
