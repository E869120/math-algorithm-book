#include <iostream>
using namespace std;

int main() {
	// ����
	int N, X, Y;
	cin >> N >> X >> Y;

	// ���������߂�
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0 || i % Y == 0) cnt++; // mod �̌v�Z�� 2.2 �ߎQ��
	}

	// �o��
	cout << cnt << endl;
	return 0;
}