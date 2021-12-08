#include <iostream>
using namespace std;

long long N, S, A[61];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// �S�p�^�[����T���F(1LL << N) �� 2 �� N ��
	for (long long i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (int j = 1; j <= N; j++) {
			// i & (1LL << (j-1)) != 0LL �̏ꍇ�Ai �� 2 �i�@�\�L�̉����� j ���ڂ� 1
			// (1LL << (j-1)) �� C++ �ł́u2 �� j-1 ��v���Ӗ����܂�
			if ((i & (1LL << (j - 1))) != 0LL) sum += A[j];
		}
		if (sum == S) { cout << "Yes" << endl; return 0; }
	}
	cout << "No" << endl;
	return 0;
}