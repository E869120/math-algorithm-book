#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, A[1000009];

int main() {
	// “ü—Í
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// ”z—ñ‚Ìƒ\[ƒg
	sort(A + 1, A + N + 1);

	// “ñ•ª’Tõ
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // ’Tõ”ÍˆÍ‚Ì’†‰›‚Å•ªŠ„‚·‚é
		if (A[mid] == X) { cout << "Yes" << endl; return 0; }
		if (A[mid] > X) right = mid - 1; // ’Tõ”ÍˆÍ‚ğ‘O”¼•”•ª‚Éi‚é
		if (A[mid] < X) left = mid + 1; // ’Tõ”ÍˆÍ‚ğŒã”¼•”•ª‚Éi‚é
	}

	// ’Tõ”ÍˆÍ‚ª‚È‚­‚È‚Á‚Ä‚à Yes ‚Æ‚È‚ç‚È‚¯‚ê‚Î“š‚¦‚Í No
	cout << "No" << endl;
	return 0;
}