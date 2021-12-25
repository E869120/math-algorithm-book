#include <stdio.h>

int N, A[200009];

int main() {
	// 入力
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	// 選択ソート
	for (i = 1; i <= N - 1; i++) {
		int min_position = i;
		int min_value = A[i];
		for (j = i + 1; j <= N; j++) {
			if (A[j] < min_value) {
				min_position = j; // min_position は最小値のインデックス（1～N）
				min_value = A[j]; // min_value は現時点での最小値
			}
		}
		// 次の 3 行で A[i] と A[min_position] を交換
		int temp = A[i];
		A[i] = A[min_position];
		A[min_position] = temp;
	}

	// 出力
	for (int i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}
