#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	if (N % 4 == 1) cout << "2" << endl;
	if (N % 4 == 2) cout << "4" << endl;
	if (N % 4 == 3) cout << "8" << endl;
	if (N % 4 == 0) cout << "6" << endl;
	return 0;
}