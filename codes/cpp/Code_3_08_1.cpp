#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, A[1000009];

int main() {
	// ����
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// �z��̃\�[�g
	sort(A + 1, A + N + 1);

	// �񕪒T��
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // �T���͈͂̒����ŕ�������
		if (A[mid] == X) { cout << "Yes" << endl; return 0; }
		if (A[mid] > X) right = mid - 1; // �T���͈͂�O�������ɍi��
		if (A[mid] < X) left = mid + 1; // �T���͈͂��㔼�����ɍi��
	}

	// �T���͈͂��Ȃ��Ȃ��Ă� Yes �ƂȂ�Ȃ���Γ����� No
	cout << "No" << endl;
	return 0;
}