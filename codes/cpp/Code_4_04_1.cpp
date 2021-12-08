#include <iostream>
using namespace std;

int N;
bool prime[100000009];

int main() {
	// ���� �� �z��̏�����
	cin >> N;
	for (int i = 2; i <= N; i++) prime[i] = true;

	// �G���g�X�e�l�X�̂ӂ邢
	for (int i = 2; i * i <= N; i++) {
		if (prime[i] == true) {
			for (int x = 2 * i; x <= N; x += i) prime[x] = false;
		}
	}

	// N �ȉ��̑f�������������ɏo��
	for (int i = 2; i <= N; i++) {
		if (prime[i] == true) cout << i << endl;
	}
	return 0;
}