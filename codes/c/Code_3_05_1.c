#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 10000; // N は試行回数（適宜変更する）
	int M = 0;
	int i;
	for (i = 1; i <= N; i++) {
		double px = rand() / (double)RAND_MAX; // 0 以上 1 以下の乱数（ランダムな数）を生成
		double py = rand() / (double)RAND_MAX; // 0 以上 1 以下の乱数（ランダムな数）を生成
		// 原点からの距離は sqrt(px * px + py * py)
		// これが 1 以下であれば良いので、条件は「px * px + py * py <= 1」
		if (px * px + py * py <= 1.0) M += 1;
	}
	printf("%.12lf\n", 4.0 * M / N);
	return 0;
}
