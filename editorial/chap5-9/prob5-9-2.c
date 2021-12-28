#include <stdio.h>
 
int compare_values(const void* a, const void* b) {
	// a の方が前に来るとき 負の値
	// b の方が前に来るとき 正の値
	// a と b が等しい値のとき 0 を返す関数
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}

long long N;
long long A[100009], B[100009];
 
int main() {
	// 入力
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	
	// ソート
	qsort(A + 1, N, sizeof(long long), compare_values);
	qsort(B + 1, N, sizeof(long long), compare_values);
	
	// 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] >= B[i]) Answer += (A[i] - B[i]);
		else Answer += (B[i] - A[i]);
	}
	printf("%lld\n", Answer);
	return 0;
}