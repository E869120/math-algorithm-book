#include <stdio.h>

int main() {
	// 入力
	long long N;
	scanf("%lld", &N);

	// 支払い方のシミュレーション
	long long answer = 0;
	while (N >= 10000) {
		N -= 10000;
		answer += 1;
	}
	while (N >= 5000) {
		N -= 5000;
		answer += 1;
	}
	while (N >= 1) {
		N -= 1000;
		answer += 1;
	}
	
	// 答えの出力
	printf("%lld\n", answer);
	return 0;
}
