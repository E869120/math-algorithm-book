#include <iostream>
using namespace std;

int main() {
	// ����
	int N, X;
	cin >> N >> X;

	// ���ׂĂ� (a, b, c) �̑g�ݍ��킹������
	int answer = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// �������o��
	cout << answer << endl;

	return 0;
}