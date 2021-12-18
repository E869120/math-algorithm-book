#include <iostream>
#include <algorithm>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
	// 入力
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 配列の初期化
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;
	
	// 動的計画法
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			// j < A[i] のとき、カード i は選べない
			if (j < A[i]) dp[i][j] = dp[i-1][j];
			// j >= A[i] のとき、選ぶ / 選ばない 両方の選択肢がある
			if (j >= A[i]) {
				if (dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
	
	// 答えを出力
	if (dp[N][S] == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}