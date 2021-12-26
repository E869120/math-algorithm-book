#include <stdio.h>

int N, a[10000009];

int main() {
	scanf("%d", &N);
	a[1] = 1; a[2] = 1;
	int i;
	for (i = 3; i <= N; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
	}
	printf("%d\n", a[N] % 1000000007);
	return 0;
}
