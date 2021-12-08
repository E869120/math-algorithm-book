#include <iostream>
using namespace std;

int N, B[100009], R[100009];

int main() {
	// “ü—Í
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 1; i <= N; i++) cin >> R[i];

	// “š‚¦‚ÌŒvZ ¨ “š‚¦‚Ìo—Í
	double Blue = 0.0, Red = 0.0;
	for (int i = 1; i <= N; i++) {
		Blue += 1.0 * B[i] / N;
		Red += 1.0 * R[i] / N;
	}
	printf("%.12lf\n", Blue + Red);
	return 0;
}