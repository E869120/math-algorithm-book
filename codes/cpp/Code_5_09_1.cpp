#include <iostream>
using namespace std;

int main() {
	// 入力
	long long N, Answer = 0;
	cin >> N;

	// 支払い方のシミュレーション → 答えの出力
	while (N >= 10000) { N -= 10000; Answer += 1; }
	while (N >= 5000) { N -= 5000; Answer += 1; }
	while (N >= 1) { N -= 1000; Answer += 1; }
	cout << Answer << endl;
	return 0;
}