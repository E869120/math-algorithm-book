#include <iostream>
#include <vector>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009]; // G[i] �͒��_ i �ɗאڂ��钸�_�̃��X�g

int main() {
	// ����
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // ���_ A[i] �ɗאڂ��钸�_�Ƃ��� B[i] ��ǉ�
		G[B[i]].push_back(A[i]); // ���_ B[i] �ɗאڂ��钸�_�Ƃ��� A[i] ��ǉ�
	}

	// �o�́iG[i].size() �͒��_ i �ɗאڂ��钸�_�̃��X�g�̑傫�� = �����j
	for (int i = 1; i <= N; i++) {
		cout << i << ": {";
		for (int j = 0; j < G[i].size(); j++) {
			if (j >= 1) cout << ","; // �R���}��؂�ŏo�͂���
			cout << G[i][j]; // G[i][j] �͒��_ i �ɗאڂ��钸�_�̂��� j �Ԗڂ̂���
		}
		cout << "}" << endl;
	}
	return 0;
}