#include <iostream>
using namespace std;

int main() {
	double r = 2.0; // ��2 �����߂�������
	double a = 2.0; // �����l��K���� 2.0 �ɃZ�b�g����

	for (int i = 1; i <= 5; i++) {
		// �_ (a, f(a)) �� x ���W�� y ���W�����߂�
		double zahyou_x = a;
		double zahyou_y = a * a;

		// �ڐ��̌X�������߂� [y = (sessen_a)x + sessen_b �Ƃ���]
		double sessen_a = 2.0 * zahyou_x;
		double sessen_b = zahyou_y - sessen_a * zahyou_x;

		// ���� a �̒l next_a �����߂�
		double next_a = (r - sessen_b) / sessen_a;
		printf("Step #%d: a = %.12lf -> %.12lf\n", i, a, next_a);
		a = next_a;
	}
	return 0;
}