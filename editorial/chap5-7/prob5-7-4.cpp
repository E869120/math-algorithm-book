#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long X[200009], Y[200009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	
	// 配列をソートする
	sort(X + 1, X + N + 1);
	sort(Y + 1, Y + N + 1);
	
	// パーツ 1 の答え（x 座標の差の絶対値の総和）
	long long Part1 = 0;
	for (int i = 1; i <= N; i++) Part1 += X[i] * (-N + 2LL * i - 1LL);
	
	// パーツ 2 の答え（y 座標の差の絶対値の総和）
	long long Part2 = 0;
	for (int i = 1; i <= N; i++) Part2 += Y[i] * (-N + 2LL * i - 1LL);
	
	// 出力
	cout << Part1 + Part2 << endl;
	return 0;
}