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

long long N;
long long X[200009], Y[200009];

int main() {
	// 入力
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld%lld", &X[i], &Y[i]);
	
	// 配列をソートする
	qsort(X + 1, N, sizeof(long long), compare_values);
	qsort(Y + 1, N, sizeof(long long), compare_values);
	
	// パーツ 1 の答え（x 座標の差の絶対値の総和）
	long long Part1 = 0;
	for (int i = 1; i <= N; i++) Part1 += X[i] * (-N + 2LL * i - 1LL);
	
	// パーツ 2 の答え（y 座標の差の絶対値の総和）
	long long Part2 = 0;
	for (int i = 1; i <= N; i++) Part2 += Y[i] * (-N + 2LL * i - 1LL);
	
	// 出力
	printf("%lld\n", Part1 + Part2);
	return 0;
}