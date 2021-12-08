#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		cout << i << endl; // i ‚ð–ñ”‚É’Ç‰Á
		if (i != N / i) {
			cout << N / i << endl; // i ‚ N/i ‚Ì‚Æ‚«AN/i ‚à–ñ”‚É’Ç‰Á
		}
	}
	return 0;
}