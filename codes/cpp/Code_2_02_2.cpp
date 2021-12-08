#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b; // a と b を入力する
	cout << (a & b) << endl; // a AND b の値を出力する
	cout << (a | b) << endl; // a OR b の値を出力する
	cout << (a ^ b) << endl; // a XOR b の値を出力する
	return 0;
}