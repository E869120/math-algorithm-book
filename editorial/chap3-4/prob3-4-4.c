#include <stdio.h>

int N;
double Answer = 0;

int main() {
	// 入力
	scanf("%d", &N);
	
	// 期待値を求める
	for (int i = N; i >= 1; i--) {
		Answer += 1.0 * N / i;
	}
	
	// 出力
	printf("%.12lf\n", Answer);
	return 0;
}