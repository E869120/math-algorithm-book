#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		cout << i << endl; // i ��񐔂ɒǉ�
		if (i != N / i) {
			cout << N / i << endl; // i �� N/i �̂Ƃ��AN/i ���񐔂ɒǉ�
		}
	}
	return 0;
}