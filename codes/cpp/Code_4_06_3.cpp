#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long a, b, Answer = 1; // a の 0 乗は 1 なので、Answer=1 に初期化しておく

int main() {
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		Answer = (Answer * a) % mod;
	}
	cout << Answer << endl;
	return 0;
}