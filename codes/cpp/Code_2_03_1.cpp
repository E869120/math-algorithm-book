#include <iostream>
using namespace std;

int cnt = 1000;

int func1() {
	return 2021;
}

int func2(int pos) {
	cnt += 1;
	return cnt + pos;
}

int main() {
	cout << func1() << endl; // �u2021�v�Əo��
	cout << func2(500) << endl; // �u1501�v�Əo��
	cout << func2(500) << endl; // �u1502�v�Əo��
	return 0;
}