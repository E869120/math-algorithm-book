#include <stdio.h>

int main() {
	// 入力
	int N, K, A[59];
	scanf("%d%d", &N, &K);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 数列の要素の総和 sum を求める
	int sum = 0;
	for (i = 1; i <= N; i++) {
		sum += A[i];
	}

	// 答えの出力
	if (sum % 2 != K % 2) {
		printf("No\n");
	}
	else if (sum > K) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}
