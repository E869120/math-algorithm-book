#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, X[59], Y[59];
long long Answer = (1LL << 62); // ���蓾�Ȃ��l�ɐݒ�

int check_numpoints(int lx, int rx, int ly, int ry) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		// �_ (X[i], Y[i]) �������`�Ɋ܂܂�Ă��邩�ǂ����𔻒肷��
		if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) cnt++;
	}
	return cnt;
}

int main() {
	// ����
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// ���[ x�A�E�[ x�A���[ y�A��[ y ��S�T���i���ꂼ��̔ԍ��� i, j, k, l�j
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) {
					int cl = X[i]; // ���[�� x ���W
					int cr = X[j]; // �E�[�� x ���W
					int dl = Y[k]; // ���[�� y ���W
					int dr = Y[l]; // ��[�� y ���W
					if (check_numpoints(cl, cr, dl, dr) >= K) {
						long long area = 1LL * (cr - cl) * (dr - dl);
						Answer = min(Answer, area);
					}
				}
			}
		}
	}

	// �����̏o��
	cout << Answer << endl;
	return 0;
}