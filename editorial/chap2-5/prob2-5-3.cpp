#include <iostream>
using namespace std;

int main() {
	long long N;
	long long Answer = 1;
	cin >> N;
	for (int i = 2; i <= N; i++) Answer *= i; // Answer に i を掛ける
	cout << Answer << endl;
	return 0;
}