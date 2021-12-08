#include <iostream>
using namespace std;

const long long mod = 1000000007;
int X, Y;

long long modpow(long long a, long long b, long long m) {
	// �J��Ԃ����@�ip �� a^1, a^2, a^4, a^8, ... �Ƃ������l���Ƃ�j
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

// Division(a, b, m) �� a��b mod m ��Ԃ��֐�
long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// ����
	cin >> X >> Y;

	// �񍀌W���̕��q�ƕ�������߂�i�菇 1.�^�菇 2.�j
	long long bunshi = 1, bunbo = 1;
	for (int i = 1; i <= X + Y; i++) { bunshi *= i; bunshi %= mod; }
	for (int i = 1; i <= X; i++) { bunbo *= i; bunbo %= mod; }
	for (int i = 1; i <= Y; i++) { bunbo *= i; bunbo %= mod; }

	// ���������߂�i�菇 3.�j
	cout << Division(bunshi, bunbo, mod) << endl;
	return 0;
}