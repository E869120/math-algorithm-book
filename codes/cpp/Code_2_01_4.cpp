#include <iostream>
#include <string>
using namespace std;

int N;
string Answer = ""; // string �͕�����^

int main() {
	cin >> N; // ���͕���
	while (N >= 1) {
		// N % 2 �� N �� 2 �Ŋ������]��i��FN=13 �̏ꍇ 1�j
		// N / 2 �� N �� 2 �Ŋ������l�̐��������i��FN=13 �̏ꍇ 6�j
		if (N % 2 == 0) Answer = "0" + Answer;
		if (N % 2 == 1) Answer = "1" + Answer;
		N = N / 2;
	}
	cout << Answer << endl; // �o�͕���
	return 0;
}