#include <stdio.h>

const long long mod = 1000000007;
long long N;
long long A[300009];
long long power[300009];

int main() {
	// 入力
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 2^i を求める
	power[0] = 1;
	for (int i = 1; i <= N; i++) {
		power[i] = (2 * power[i - 1]) % mod;
	}
	
	// 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += power[i - 1] * A[i];
		Answer %= mod;
	}
	
	// 出力
	printf("%lld\n", Answer);
	return 0;
}