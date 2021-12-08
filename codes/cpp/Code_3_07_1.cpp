#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, H[100009], dp[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];

	// 動的計画法 → 答えの出力
	for (int i = 1; i <= N; i++) {
		if (i == 1) dp[i] = 0;
		if (i == 2) dp[i] = abs(H[i - 1] - H[i]);
		if (i >= 3) {
			int v1 = dp[i - 1] + abs(H[i - 1] - H[i]); // 1 個前の足場からジャンプするとき
			int v2 = dp[i - 2] + abs(H[i - 2] - H[i]); // 2 個前の足場からジャンプするとき
			dp[i] = min(v1, v2);
		}
	}
	cout << dp[N] << endl;
	return 0;
}