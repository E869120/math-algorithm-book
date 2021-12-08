#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// ����
	long long ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	// �x�N�g�� BA, BC, CA, CB �̐����\�������߂�
	long long BAx = (ax - bx), BAy = (ay - by);
	long long BCx = (cx - bx), BCy = (cy - by);
	long long CAx = (ax - cx), CAy = (ay - cy);
	long long CBx = (bx - cx), CBy = (by - cy);

	// �ǂ̃p�^�[���ɓ��Ă͂܂邩�𔻒肷��
	int pattern = 2;
	if (BAx * BCx + BAy * BCy < 0LL) pattern = 1;
	if (CAx * CBx + CAy * CBy < 0LL) pattern = 3;

	// �_�ƒ����̋��������߂�
	double Answer = 0.0;
	if (pattern == 1) Answer = sqrt(BAx * BAx + BAy * BAy);
	if (pattern == 3) Answer = sqrt(CAx * CAx + CAy * CAy);
	if (pattern == 2) {
		double S = abs(BAx * CAy - BAy * CAx);
		double BCLength = sqrt(BCx * BCx + BCy * BCy);
		Answer = S / BCLength;
	}

	// �����̏o��
	printf("%.12lf\n", Answer);
	return 0;
}