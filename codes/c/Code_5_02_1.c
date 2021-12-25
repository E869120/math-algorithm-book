#include <stdio.h>

int main() {
	long long N;
	scanf("%lld", &N);
	if (N % 4 == 1) printf("2\n");
	if (N % 4 == 2) printf("4\n");
	if (N % 4 == 3) printf("8\n");
	if (N % 4 == 0) printf("6\n");
	return 0;
}
