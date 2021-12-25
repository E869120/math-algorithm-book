#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// 2 つの long long 型の値を比較する関数（Code_3_06_1.c を参照）
	if (*(long long*)a < *(long long*)b) return -1;
	if (*(long long*)a > *(long long*)b) return +1;
	return 0;
}

int N; long long X, A[1000009];

int main() {
	// 入力
	scanf("%d%lld", &N, &X);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	// 配列のソート（Code_3_06_1.c を参照）
	qsort(A + 1, N, sizeof(long long), compare_values);

	// 二分探索
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // 探索範囲の中央で分割する
		if (A[mid] == X) {
			printf("Yes\n");
			return 0;
		}
		if (A[mid] > X) right = mid - 1; // 探索範囲を前半部分に絞る
		if (A[mid] < X) left = mid + 1; // 探索範囲を後半部分に絞る
	}

	// 探索範囲がなくなっても Yes とならなければ答えは No
	printf("No\n");
	return 0;
}
