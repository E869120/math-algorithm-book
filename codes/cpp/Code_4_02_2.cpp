#include <iostream>
using namespace std;

int N, B[100009];
int Q, L[100009], R[100009], X[100009];

int main() {
	// “ü—ÍEŠK·‚ÌŒvZ
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> L[i] >> R[i] >> X[i];
		B[L[i]] += X[i];
		B[R[i] + 1] -= X[i];
	}

	// “š‚¦‚Ìo—Í
	for (int i = 1; i <= N - 1; i++) {
		if (B[i] > 0) cout << "<";
		if (B[i] == 0) cout << "=";
		if (B[i] < 0) cout << ">";
	}
	cout << endl;
	return 0;
}