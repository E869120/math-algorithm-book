#include <iostream>
using namespace std;

int N, dp[54];

int main() {
	// 入力
	cin >> N;

	// 動的計画法 → 答えの出力
	for (int i = 0; i <= N; i++) {
		if (i <= 1) dp[i] = 1;
		else dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N] << endl;
	return 0;
}