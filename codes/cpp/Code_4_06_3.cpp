#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long a, b, Answer = 1; // a �� 0 ��� 1 �Ȃ̂ŁAAnswer=1 �ɏ��������Ă���

int main() {
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		Answer = (Answer * a) % mod;
	}
	cout << Answer << endl;
	return 0;
}