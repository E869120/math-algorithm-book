#include <iostream>
using namespace std;

int main() {
	// ����
	long long N, Answer = 0;
	cin >> N;

	// �x�������̃V�~�����[�V���� �� �����̏o��
	while (N >= 10000) { N -= 10000; Answer += 1; }
	while (N >= 5000) { N -= 5000; Answer += 1; }
	while (N >= 1) { N -= 1000; Answer += 1; }
	cout << Answer << endl;
	return 0;
}