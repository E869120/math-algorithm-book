#include <iostream>
using namespace std;

int main() {
	// “ü—Í
	int N, X;
	cin >> N >> X;

	// ‚·‚×‚Ä‚Ì (a, b, c) ‚Ì‘g‚İ‡‚í‚¹‚ğ‚·
	int answer = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// “š‚¦‚ğo—Í
	cout << answer << endl;

	return 0;
}