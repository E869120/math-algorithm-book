#include <iostream>
#include <string>
using namespace std;

int N;
string Answer = ""; // string は文字列型

int main() {
	cin >> N; // 入力部分
	while (N >= 1) {
		// N % 2 は N を 2 で割った余り（例：N=13 の場合 1）
		// N / 2 は N を 2 で割った値の整数部分（例：N=13 の場合 6）
		if (N % 2 == 0) Answer = "0" + Answer;
		if (N % 2 == 1) Answer = "1" + Answer;
		N = N / 2;
	}
	cout << Answer << endl; // 出力部分
	return 0;
}