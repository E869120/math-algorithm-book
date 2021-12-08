#include <iostream>
using namespace std;

int main() {
	// “ü—Í
	int N, X, Y;
	cin >> N >> X >> Y;

	// “š‚¦‚ğ‹‚ß‚é
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0 || i % Y == 0) cnt++; // mod ‚ÌŒvZ‚Í 2.2 ßQÆ
	}

	// o—Í
	cout << cnt << endl;
	return 0;
}