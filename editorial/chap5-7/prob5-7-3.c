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
 
long long N, A[200009];
long long Answer = 0;
 
int main() {
	// 入力
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld\n", &A[i]);
	
	// ソート（コード 5.7.1 から追加した唯一の部分）
	qsort(A + 1, N, sizeof(long long), compare_values);
	
	// 答えを求める → 答えの出力
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	printf("%lld\n", Answer);
	return 0;
}