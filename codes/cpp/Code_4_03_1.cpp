#include <iostream>
using namespace std;

int main() {
	double r = 2.0; // √2 を求めたいから
	double a = 2.0; // 初期値を適当に 2.0 にセットする

	for (int i = 1; i <= 5; i++) {
		// 点 (a, f(a)) の x 座標と y 座標を求める
		double zahyou_x = a;
		double zahyou_y = a * a;

		// 接線の傾きを求める [y = (sessen_a)x + sessen_b とする]
		double sessen_a = 2.0 * zahyou_x;
		double sessen_b = zahyou_y - sessen_a * zahyou_x;

		// 次の a の値 next_a を求める
		double next_a = (r - sessen_b) / sessen_a;
		printf("Step #%d: a = %.12lf -> %.12lf\n", i, a, next_a);
		a = next_a;
	}
	return 0;
}