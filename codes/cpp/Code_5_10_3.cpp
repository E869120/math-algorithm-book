#include <iostream>
using namespace std;

long long N, X, Y;

int main() {
	// ����
	cin >> N >> X >> Y;

	// 4 �̐��� (a, b, c, d) �̑S�T�� �� �����̏o��
	for (int a = 1; a <= N; a++) {
		for (int b = a; b <= N; b++) {
			for (int c = b; c <= N; c++) {
				for (int d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						cout << "Yes" << endl;
						return 0; // �v���O�����̎��s���I��������
					}
				}
			}
		}
	}
	cout << "No" << endl; // 1 ��������Ȃ������� No
	return 0;
}