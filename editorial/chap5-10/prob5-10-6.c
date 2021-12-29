#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// a の方が前に来るとき 負の値
	// b の方が前に来るとき 正の値
	// a と b が等しい値のとき 0 を返す関数
	if (*(long long*)a < *(long long*)b) return -1;
	if (*(long long*)a > *(long long*)b) return +1;
	return 0;
}

// 各桁の積の候補
int cand_size = 0;
long long fm_cand[10000000];

// m の各桁の積を返す関数
long long product(long long m) {
	long long ans = 1;
	if (m == 0) ans = 0;
	while (m >= 1) {
		ans *= (m % 10);
		m /= 10;
	}
	return ans;
}

// m の桁数は 11 桁以下
void func(int digit, long long m) {
	if (digit == 11) {
		fm_cand[cand_size] = product(m);
		cand_size += 1;
		return;
	}
 
	// 次の桁を探索
	// min_value は cur の最後の桁（単調増加にするためには次の桁がそれ以上でなければならない）
	int min_value = (m % 10);
	for (int i = min_value; i <= 9; i++) {
		func(digit + 1, 10LL * m + 1LL * i);
	}
}
 
int main() {
	// f(m) の候補を列挙
	for (int i = 0; i <= 9; i++) {
		func(1, i);
	}
 
	// fm_cand をソートする
	qsort(fm_cand, cand_size, sizeof(long long), compare_values);
 
	// 入力
	long long N, B;
	scanf("%lld%lld", &N, &B);
 
	// m - f(m) = B になるかどうかチェック
	long long Answer = 0;
	for (int i = 0; i < cand_size; i++) {
		if (i >= 1 && fm_cand[i - 1] == fm_cand[i]) {
			// 前に調べたことがある要素は調べない
			continue;
		}
		long long m = fm_cand[i] + B;
		long long prod_m = product(m);
		if (prod_m == fm_cand[i] && m <= N) {
			Answer += 1;
		}
	}
 
	// 出力
	printf("%lld\n", Answer);
	return 0;
}