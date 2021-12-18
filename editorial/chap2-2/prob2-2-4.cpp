#include <iostream>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// “ü—Í
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	// “š‚¦‚ÌŒvŽZ
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// o—Í
	cout << Answer % 100 << endl;
	return 0;
}