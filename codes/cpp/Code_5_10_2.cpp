#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (c - a - b < 0LL) cout << "No" << endl;
	else if (4LL * a * b < (c - a - b) * (c - a - b)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}