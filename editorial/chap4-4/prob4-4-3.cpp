#include <iostream>
using namespace std;

long long N;
long long F[10000009];
long long Answer = 0;

int main() {
	// 入力 → 配列の初期化
	cin >> N;
	for (int i = 1; i <= N; i++) F[i] = 0;
	
	// F[1], F[2], ..., F[N] を計算する
	for (int i = 1; i <= N; i++) {
		// F[i], F[2i], F[3i], ... に 1 を加算
		for (int j = i; j <= N; j += i) F[j] += 1;
	}
	
	// 答えを求める → 出力
	for (int i = 1; i <= N; i++) {
		Answer += 1LL * i * F[i];
	}
	cout << Answer << endl;
	return 0;
}