#include <stdio.h>

int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	const long long MOD = 1000000007;
	long long answer = 1; // a の 0 乗は 1 なので、Answer=1 に初期化しておく
	long long i;
	for (i = 1; i <= b; i++) {
		answer = (answer * a) % MOD;
	}
	printf("%lld\n", answer);
	return 0;
}
