#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (sqrt(a) + sqrt(b) < sqrt(c)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}