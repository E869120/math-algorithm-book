#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int N = 1000000;
	int M = 0;
	
	for (int i = 1; i <= N; i++) {
		double px = 6.0 * rand() / (double)RAND_MAX;
		double py = 9.0 * rand() / (double)RAND_MAX;
		
		// 点 (3, 3) との距離。この値が 3 以下であれば半径 3 の円に含まれる。
		double dist_33 = sqrt((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0));
		
		// 点 (3, 7) との距離。この値が 2 以下であれば半径 2 の円に含まれる。
		double dist_37 = sqrt((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0));
		
		// 条件分岐
		if (dist_33 <= 3.0 || dist_37 <= 2.0) M += 1;
	}
	
	// N 回中何回表に入ったかを出力
	printf("%d\n", M);
	return 0;
}