#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long a, b, Answer = 1; // a ‚Ì 0 æ‚Í 1 ‚È‚Ì‚ÅAAnswer=1 ‚É‰Šú‰»‚µ‚Ä‚¨‚­

int main() {
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		Answer = (Answer * a) % mod;
	}
	cout << Answer << endl;
	return 0;
}