#include <stdio.h>

int main() {
	// 入力
	long long N, S, A[61];
	scanf("%lld%lld", &N, &S);
	long long i, j;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}
	
	// 全パターンを探索：(1LL << N) は 2 の N 乗
	for (i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (j = 1; j <= N; j++) {
			// (i & (1LL << (j-1))) != 0LL の場合、i の 2 進法表記の下から j 桁目が 1
			// (1LL << (j-1)) は C++ では「2 の j-1 乗」を意味します
			if ((i & (1LL << (j - 1))) != 0LL) {
				sum += A[j];
			}
		}
		if (sum == S) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
