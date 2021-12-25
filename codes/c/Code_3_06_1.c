#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// a の方が前に来るとき 負の値
	// b の方が前に来るとき 正の値
	// a と b が等しい値のとき 0 を返す関数
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}

int N, A[200009];

int main() {
	// 入力（たとえば N=5, A[1]=3, A[2]=1, A[3]=4, A[4]=1, A[5]=5 を入力したとする）
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// ソート（A[1] から始まる N 個の要素をソートするので、引数に A+1, N を指定している）
	// qsort 関数により、配列の中身が [3,1,4,1,5] から [1,1,3,4,5] に書き換えられる
	qsort(A + 1, N, sizeof(int), compare_values);
	
	// 出力（1, 1, 3, 4, 5 の順に出力される）
	for (i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	
	return 0;
}
