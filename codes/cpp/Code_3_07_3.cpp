#include <iostream>
#include <algorithm>
using namespace std;

long long N, W, w[109], v[109];
long long dp[109][100009];

int main() {
	// ����
	cin >> N >> W;
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

	// �z��̏�����
	dp[0][0] = 0;
	for (int i = 1; i <= W; i++) dp[0][i] = -(1LL << 60);

	// ���I�v��@
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			// j<w[i] �̂Ƃ��A���@ B ���Ƃ�I�ѕ����ł��Ȃ�
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			// j>=w[i] �̂Ƃ��A���@ A�E���@ B �ǂ�����I�ׂ�
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	// �������o��
	long long Answer = 0;
	for (int i = 0; i <= W; i++) Answer = max(Answer, dp[N][i]);
	cout << Answer << endl;
	return 0;
}