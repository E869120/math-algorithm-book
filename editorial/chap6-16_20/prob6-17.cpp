#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// ����
	long long N;
	cin >> N;

	// �c�̒����� 1 ���� ��N �܂őS�T��
	long long answer = (1LL << 60);
	for (long long x = 1; x * x <= N; x++) {
		if (N % x == 0) {
			answer = min(answer, 2 * x + 2 * (N / x));
		}
	}

	// �������o��
	cout << answer << endl;

	return 0;
}