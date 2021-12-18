#include <stdio.h>

int N, A[109];
int Answer = 0;

int main() {
	// “ü—Í
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	// “š‚¦‚ÌŒvŽZ
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// o—Í
	printf("%d\n", Answer % 100);
	return 0;
}