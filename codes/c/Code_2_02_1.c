#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 四則演算
	printf("%d\n", 869 + 120); // 989 と出力
	printf("%d\n", 869 - 120); // 749 と出力
	printf("%d\n", 869 * 120); // 104280 と出力
	printf("%d\n", 869 / 120); // 7 と出力（ここでは整数部分のみを出力することに注意）

	// 剰余（mod）
	printf("%d\n", 8 % 5); // 3 と出力
	printf("%d\n", 869 % 120); // 29 と出力

	// 絶対値（abs）（注： C 言語で abs を使うためには <stdlib.h> をインクルード）
	printf("%d\n", abs(-45)); // 45 と出力
	printf("%d\n", abs(15)); // 15 と出力

	// 累乗（pow）
	printf("%d\n", (int)pow(10.0, 2.0)); // 100 と出力
	printf("%d\n", (int)pow(3.0, 4.0)); // 81 と出力

	// ルート（sqrt）
	printf("%.5lf\n", sqrt(4.0)); // 2.00000 と出力
	printf("%.5lf\n", sqrt(2.0)); // 1.41421 と出力
	return 0;
}
