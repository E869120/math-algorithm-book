#include <stdio.h>
#include <stdbool.h>

int N;
double A[509], B[509], C[509];

bool check(double x, double y) {
	for (int i = 1; i <= N; i++) {
		if (A[i] * x + B[i] * y > C[i]) return false;
	}
	return true;
}

// a1 と a2 の最大値を返す関数
double max(double a1, double a2) {
	if (a1 < a2) {
		return a2;
	}
	return a1;
}

int main() {
	// 入力
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lf%lf%lf", &A[i], &B[i], &C[i]);
	
	// 交点を全探索
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// 交点をもたない場合
			if (A[i] * B[j] == A[j] * B[i]) continue;
			
			// i 番目の直線（条件式の境界）と j 番目の直線（条件式の境界）の交点を求める
			double px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
			double py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
			bool ret = check(px, py);
			if (ret == true) {
				Answer = max(Answer, px + py);
			}
		}
	}
	
	// 答えを出力
	printf("%.12lf\n", Answer);
	return 0;
}