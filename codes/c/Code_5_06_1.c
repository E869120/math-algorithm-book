#include <stdio.h>
#include <stdbool.h>

// 小問題 t を解く関数
bool shou_mondai(int A, int B, int t) {
	int cl = (A + t - 1) / t; // A÷t の小数点以下切り上げ
	int cr = B / t; // B÷t の小数点以下切り捨て
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int answer = 0;
	int i;
	for (i = 1; i <= B; i++) {
		if (shou_mondai(A, B, i) == true) {
			answer = i;
		}
	}
	printf("%d\n", answer);
	return 0;
}
