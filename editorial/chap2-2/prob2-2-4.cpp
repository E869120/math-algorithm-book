#include <iostream>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	// 答えの計算
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// 出力
	cout << Answer % 100 << endl;
	return 0;
}
