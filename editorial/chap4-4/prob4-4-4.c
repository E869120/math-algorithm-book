#include <stdio.h>

int main() {
	// パラメータの設定・初期化
	long long cnt = 0;
	double LIMIT = 23; // これを 30 にすれば答えが求められる
	double Current = 0;
	
	// 1 つずつ足していく
	while (Current < LIMIT) {
		cnt += 1;
		Current += 1.0 / cnt;
	}
	
	// 答えを出力
	printf("%lld\n", cnt);
	return 0;
}