#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// �l�����Z
	printf("%d\n", 869 + 120); // 989 �Əo��
	printf("%d\n", 869 - 120); // 749 �Əo��
	printf("%d\n", 869 * 120); // 104280 �Əo��
	printf("%d\n", 869 / 120); // 7 �Əo�́i�����ł͐��������݂̂��o�͂��邱�Ƃɒ��Ӂj

	// ��]�imod�j
	printf("%d\n", 8 % 5); // 3 �Əo��
	printf("%d\n", 869 % 120); // 29 �Əo��

	// ��Βl�iabs�j
	printf("%d\n", abs(-45)); // 45 �Əo��
	printf("%d\n", abs(15)); // 15 �Əo��

	// �ݏ�ipow�j
	printf("%d\n", (int)pow(10.0, 2.0)); // 100 �Əo��
	printf("%d\n", (int)pow(3.0, 4.0)); // 81 �Əo��

	// ���[�g�isqrt�j
	printf("%.5lf\n", sqrt(4.0)); // 2.00000 �Əo��
	printf("%.5lf\n", sqrt(2.0)); // 1.41421 �Əo��
	return 0;
}