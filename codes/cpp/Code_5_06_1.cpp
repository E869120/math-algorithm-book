#include <iostream>
using namespace std;

int A, B, Answer = 0;

// ����� t �������֐�
bool shou_mondai(int t) {
	int cl = (A + t - 1) / t; // A��t �̏����_�ȉ��؂�グ
	int cr = B / t; // B��t �̏����_�ȉ��؂�̂�
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	cin >> A >> B;
	for (int i = 1; i <= B; i++) {
		if (shou_mondai(i) == true) Answer = i;
	}
	cout << Answer << endl;
	return 0;
}