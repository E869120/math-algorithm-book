#include <stdio.h>
#include <stdbool.h>

int N; bool prime[100000009];

int main() {
	// 入力 → 配列の初期化
	scanf("%d", &N);
	int i, x;
	for (i = 2; i <= N; i++) {
		prime[i] = true;
	}

	// エラトステネスのふるい
	for (i = 2; i * i <= N; i++) {
		if (prime[i] == true) {
			for (x = 2 * i; x <= N; x += i) {
				prime[x] = false;
			}
		}
	}

	// N 以下の素数を小さい順に出力
	for (i = 2; i <= N; i++) {
		if (prime[i] == true) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
