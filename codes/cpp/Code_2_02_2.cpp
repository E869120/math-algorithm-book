#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b; // a �� b ����͂���
	cout << (a & b) << endl; // a AND b �̒l���o�͂���
	cout << (a | b) << endl; // a OR b �̒l���o�͂���
	cout << (a ^ b) << endl; // a XOR b �̒l���o�͂���
	return 0;
}