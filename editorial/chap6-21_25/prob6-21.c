#include <math.h>
#include <stdio.h>

int main() {
	double r = 2.0; // y = e^x と y = 2 の交点を求めたいから
	double a = 1.0; // 初期値を適当に 1.0 にセットする
	int i;
	for (i = 1; i <= 5; i++) {
		// 点 (a, f(a)) の x 座標と y 座標を求める
		double zahyou_x = a;
		double zahyou_y = exp(a);

		// 接線の傾きを求める [y = (sessen_a)x + sessen_b とする]
		double sessen_a = zahyou_y;
		double sessen_b = zahyou_y - sessen_a * zahyou_x;

		// 次の a の値 next_a を求める
		double next_a = (r - sessen_b) / sessen_a;
		printf("Step #%d: a = %.15lf -> %.15lf\n", i, a, next_a);
		a = next_a;
	}
	return 0;
}