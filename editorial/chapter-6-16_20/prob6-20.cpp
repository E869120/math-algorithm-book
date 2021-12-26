#include <iostream>
using namespace std;

int N, Q, C[100009], P[100009], L[100009], R[100009], S1[100009], S2[100009];

int main() {
	// “ü—Í ¨ —ÝÏ˜a‚ð‹‚ß‚é
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i] >> P[i];
	for (int i = 1; i <= N; i++) S1[i] = S1[i - 1] + (C[i] == 1 ? P[i] : 0);
	for (int i = 1; i <= N; i++) S2[i] = S2[i - 1] + (C[i] == 2 ? P[i] : 0);

	// Ž¿–â‚É“š‚¦‚é
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> L[i] >> R[i];
		cout << S1[R[i]] - S1[L[i] - 1] << " " << S2[R[i]] - S2[L[i] - 1] << endl;
	}
	return 0;
}