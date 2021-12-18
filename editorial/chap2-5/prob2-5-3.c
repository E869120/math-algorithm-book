#include <stdio.h>

int main() {
	// 入力
	int N;
	scanf("%d", &N);
	
	// 答えの計算
	long long Answer = 1;
	for (int i = 2; i <= N; i++) Answer *= i;
	
	// 出力
	printf("%lld\n", Answer);
	return 0;
}