#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max({ a * c, a * d, b * c, b * d }) << endl;
	return 0;
}