#include <iostream>
using namespace std;

int N, K, A[59];
int sum = 0; // A[1] + A[2] + ... + A[N] �̒l

int main() {
	// ���� �� ����̗v�f�̑��a sum �����߂�
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) sum += A[i];

	// �����̏o��
	if (sum % 2 != K % 2) cout << "No" << endl;
	else if (sum > K) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}