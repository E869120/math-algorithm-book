#include <iostream>
using namespace std;

long long N, A[200009];
long long cnt[100009];
long long Answer = 0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// cnt[1], cnt[2], ..., cnt[99999] を数える
	for (int i = 1; i <= 99999; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i]] += 1;
	
	// 答えを求める
	for (int i = 1; i <= 49999; i++) {
		Answer += cnt[i] * cnt[100000 - i];
	}
	Answer += cnt[50000] * (cnt[50000] - 1) / 2;
	
	// 出力
	cout << Answer << endl;
	return 0;
}