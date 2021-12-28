#include <stdio.h>

int main() {
	// 入力
	long long N, Answer = 0;
	scanf("%lld", &N);
	
	// 10000 円札を支払う
	Answer += (N / 10000); N %= 10000;
	
	// 5000 円札を支払う
	Answer += (N / 5000); N %= 5000;
	
	// 1000 円札を支払う
	Answer += (N / 1000); N %= 1000;
	
	// 答えを出力
	printf("%lld\n", Answer);
	return 0;
}