#include <iostream>
using namespace std;

long long L, R; bool prime[500009];

int main() {
	// 入力
	cin >> L >> R;

	// 配列の初期化
	for (long long i = 0; i <= R - L; i++) {
		prime[i] = true;
	}

	// L = 1 のときの場合分け（コーナーケース）
	if (L == 1) prime[0] = false;

	// ふるい
	for (long long i = 2; i * i <= R; i++) {
		long long min_value = ((L + i - 1) / i) * i; // L 以上で最小の i の倍数
		// L 以上 R 以下の（i を除く）i の倍数すべてにバツを付ける
		for (long long j = min_value; j <= R; j += i) {
			if (j == i) continue;
			prime[j - L] = false;
		}
	}

	// 個数を数えて出力
	long long answer = 0;
	for (long long i = 0; i <= R - L; i++) {
		if (prime[i] == true) answer += 1;
	}
	cout << answer << endl;
	return 0;
}