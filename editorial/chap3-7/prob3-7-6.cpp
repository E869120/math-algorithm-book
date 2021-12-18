#include <iostream>
#include <algorithm>
using namespace std;

long long N, A[500009];
long long dp1[500009], dp2[500009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 配列の初期化
	dp1[0] = 0;
	dp2[0] = 0;
	
	// 動的計画法
	for (int i = 1; i <= N; i++) {
		dp1[i] = dp2[i - 1] + A[i];
		dp2[i] = max(dp1[i - 1], dp2[i - 1]);
	}
	
	// 答えを出力
	cout << max(dp1[N], dp2[N]) << endl;
	return 0;
}