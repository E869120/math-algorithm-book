#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 入力
	long long ax, ay, bx, by, cx, cy;
	scanf("%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &cx, &cy);

	// ベクトル BA, BC, CA, CB の成分表示を求める
	long long BAx = (ax - bx), BAy = (ay - by);
	long long BCx = (cx - bx), BCy = (cy - by);
	long long CAx = (ax - cx), CAy = (ay - cy);
	long long CBx = (bx - cx), CBy = (by - cy);

	// どのパターンに当てはまるかを判定する
	int pattern = 2;
	if (BAx * BCx + BAy * BCy < 0LL) pattern = 1;
	if (CAx * CBx + CAy * CBy < 0LL) pattern = 3;

	// 点と直線の距離を求める
	double answer = 0.0;
	if (pattern == 1) answer = sqrt(BAx * BAx + BAy * BAy);
	if (pattern == 3) answer = sqrt(CAx * CAx + CAy * CAy);
	if (pattern == 2) {
		double S = llabs(BAx * CAy - BAy * CAx);
		double BCLength = sqrt(BCx * BCx + BCy * BCy);
		answer = S / BCLength;
	}

	// 答えの出力
	printf("%.12lf\n", answer);
	return 0;
}
