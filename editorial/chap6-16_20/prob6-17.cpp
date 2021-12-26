#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// “ü—Í
	long long N;
	cin >> N;

	// c‚Ì’·‚³‚ğ 1 ‚©‚ç ãN ‚Ü‚Å‘S’Tõ
	long long answer = (1LL << 60);
	for (long long x = 1; x * x <= N; x++) {
		if (N % x == 0) {
			answer = min(answer, 2 * x + 2 * (N / x));
		}
	}

	// “š‚¦‚ğo—Í
	cout << answer << endl;

	return 0;
}