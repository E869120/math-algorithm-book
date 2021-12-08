#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, H[100009], dp[100009];

int main() {
	// ����
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];

	// ���I�v��@ �� �����̏o��
	for (int i = 1; i <= N; i++) {
		if (i == 1) dp[i] = 0;
		if (i == 2) dp[i] = abs(H[i - 1] - H[i]);
		if (i >= 3) {
			int v1 = dp[i - 1] + abs(H[i - 1] - H[i]); // 1 �O�̑��ꂩ��W�����v����Ƃ�
			int v2 = dp[i - 2] + abs(H[i - 2] - H[i]); // 2 �O�̑��ꂩ��W�����v����Ƃ�
			dp[i] = min(v1, v2);
		}
	}
	cout << dp[N] << endl;
	return 0;
}