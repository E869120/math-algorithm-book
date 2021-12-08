#include <stdio.h>

int main() {
	int N, A[59];
	int Answer = 0;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		Answer += A[i];
	}
	printf("%d\n", Answer);
	return 0;
}