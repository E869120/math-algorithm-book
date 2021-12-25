#include <stdio.h>

int main() {
	// 入力
	long long a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	
	// 答えを求める（answer は最初あり得ない値に設定）
	long long answer = -(1LL << 62);
	if (answer < a * c) answer = a * c;
	if (answer < a * d) answer = a * d;
	if (answer < b * c) answer = b * c;
	if (answer < b * d) answer = b * d;
	
	// 出力
	printf("%lld\n", answer);
	return 0;
}
