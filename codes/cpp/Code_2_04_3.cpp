#include <iostream>
using namespace std;

int N, S;
long long Answer = 0;

int main() {
	// “ü—Í
	cin >> N >> S;

	// “š‚¦‚ğ‹‚ß‚é
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i + j <= S) Answer += 1;
		}
	}

	// o—Í
	cout << Answer << endl;
	return 0;
}