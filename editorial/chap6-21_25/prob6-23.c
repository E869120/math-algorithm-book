#include <stdio.h>
#include <stdbool.h>

long long L, R; bool isprime[500009];

int main() {
	// 入力
	scanf("%lld%lld", &L, &R);

	// 配列の初期化
	long long i, j;
	for (i = 0; i <= R - L; i++) {
		isprime[i] = true;
	}

	// L = 1 のときの場合分け（コーナーケース）
	if (L == 1) {
		isprime[0] = false;
	}

	// ふるい
	for (i = 2; i * i <= R; i++) {
		long long min_value = ((L + i - 1) / i) * i; // L 以上で最小の i の倍数
		// L 以上 R 以下の（i を除く）i の倍数すべてにバツを付ける
		for (j = min_value; j <= R; j += i) {
			if (j == i) continue;
			isprime[j - L] = false;
		}
	}

	// 個数を数えて出力
	long long answer = 0;
	for (i = 0; i <= R - L; i++) {
		if (isprime[i] == true) {
			answer += 1;
		}
	}
	printf("%lld\n", answer);
	return 0;
}