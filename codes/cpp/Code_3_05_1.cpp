#include <iostream>
using namespace std;

int main() {
	int N = 10000; // N �͎��s�񐔁i�K�X�ύX����j
	int M = 0;
	for (int i = 1; i <= N; i++) {
		double px = rand() / (double)RAND_MAX; // 0 �ȏ� 1 �ȉ��̗����i�����_���Ȑ��j�𐶐�
		double py = rand() / (double)RAND_MAX; // 0 �ȏ� 1 �ȉ��̗����i�����_���Ȑ��j�𐶐�
		// ���_����̋����� sqrt(px * px + py * py)
		// ���ꂪ 1 �ȉ��ł���Ηǂ��̂ŁA�����́upx * px + py * py <= 1�v
		if (px * px + py * py <= 1.0) M += 1;
	}
	printf("%.12lf\n", 4.0 * M / N);
	return 0;
}