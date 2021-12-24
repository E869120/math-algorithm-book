#include <stdio.h>
#include <stdbool.h>

void swap(long long *x, long long *y) {
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

long long max(long long p1, long long p2) {
	if (p1 < p2) return p2;
	return p1;
}

long long min(long long p1, long long p2) {
	if (p1 < p2) return p1;
	return p2;
}

long long cross(long long ax, long long ay, long long bx, long long by) {
	// ベクトル (ax, ay) と (bx, by) の外積の大きさ
	return ax * by - ay * bx;
}

int main() {
	// 入力
	long long X1, Y1, X2, Y2, X3, Y3, X4, Y4;
	scanf("%lld%lld", &X1, &Y1); // 点 A の座標を入力
	scanf("%lld%lld", &X2, &Y2); // 点 B の座標を入力
	scanf("%lld%lld", &X3, &Y3); // 点 C の座標を入力
	scanf("%lld%lld", &X4, &Y4); // 点 D の座標を入力
	
	// cross(AB, AC) を計算
	long long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
	long long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
	long long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
	long long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
	
	// すべて一直線上に並んでいる場合（コーナーケース）
	// pair 型が使えないので、C++ とは実装方法がやや異なります
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		if (X1 == X2 && X2 == X3 && X3 == X4) {
			long long a = Y1, b = Y2; if (a > b) swap(&a, &b);
			long long c = Y3, d = Y4; if (c > d) swap(&c, &d);
			if (max(a, c) <= min(b, d)) printf("Yes\n");
			else printf("No\n");
		}
		else {
			long long a = X1, b = X2; if (a > b) swap(&a, &b);
			long long c = X3, d = X4; if (c > d) swap(&c, &d);
			if (max(a, c) <= min(b, d)) printf("Yes\n");
			else printf("No\n");
		}
		return 0;
	}
	
	// そうでない場合
	// IsAB: 線分 AB が点 C, D を分けるか？
	// IsCD: 線分 CD が点 A, B を分けるか？
	bool IsAB = false, IsCD = false;
	if (ans1 >= 0 && ans2 <= 0) IsAB = true;
	if (ans1 <= 0 && ans2 >= 0) IsAB = true;
	if (ans3 >= 0 && ans4 <= 0) IsCD = true;
	if (ans3 <= 0 && ans4 >= 0) IsCD = true;
	
	// 答えの出力
	if (IsAB == true && IsCD == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}