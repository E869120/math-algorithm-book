#include <stdio.h>
 
int main() {
	// 入力
	long long N;
	scanf("%lld", &N);
	
	// 出力
	printf("%lld\n", N * (N - 1) / 2);
	return 0;
}