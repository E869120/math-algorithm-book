#include <stdio.h>
 
int H, W, A[2009][2009];
int gyou[2009]; // 行の総和
int retu[2009]; // 列の総和
int Answer[2009][2009];
 
int main() {
	// 入力
	scanf("%d%d", &H, &W);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) scanf("%d", &A[i][j]);
	}
	
	// 行の総和を計算する
	for (int i = 1; i <= H; i++) {
		gyou[i] = 0;
		for (int j = 1; j <= W; j++) gyou[i] += A[i][j];
	}
	
	// 列の総和を計算する
	for (int j = 1; j <= W; j++) {
		retu[j] = 0;
		for (int i = 1; i <= H; i++) retu[j] += A[i][j];
	}
	
	// 各マスに対する答えを計算する
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Answer[i][j] = gyou[i] + retu[j] - A[i][j];
		}
	}
	
	// 空白区切りで出力
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (j >= 2) printf(" ");
			printf("%d", Answer[i][j]);
		}
		printf("\n");
	}
	return 0;
}