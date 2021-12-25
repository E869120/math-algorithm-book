#include <stdio.h>

int main() {
	// 入力
	int N, A[109];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 5 つのカードの番号 (i, j, k, l, m) を全探索
	int answer = 0;
	int i, j, k, l, m;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			for (k = j + 1; k <= N; k++) {
				for (l = k + 1; l <= N; l++) {
					for (m = l + 1; m <= N; m++) {
						if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) {
							answer += 1;
						}
					}
				}
			}
		}
	}
	
	// 出力
	printf("%d\n", answer);
	return 0;
}
