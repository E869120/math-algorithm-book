#include <iostream>
using namespace std;

int A, B, Answer = 0;

// ¬–â‘è t ‚ð‰ð‚­ŠÖ”
bool shou_mondai(int t) {
	int cl = (A + t - 1) / t; // A€t ‚Ì¬”“_ˆÈ‰ºØ‚èã‚°
	int cr = B / t; // B€t ‚Ì¬”“_ˆÈ‰ºØ‚èŽÌ‚Ä
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	cin >> A >> B;
	for (int i = 1; i <= B; i++) {
		if (shou_mondai(i) == true) Answer = i;
	}
	cout << Answer << endl;
	return 0;
}