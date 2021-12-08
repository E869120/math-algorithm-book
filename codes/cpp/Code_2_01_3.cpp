#include <iostream>
using namespace std;

int main() {
	int N, A[59];
	int Answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		Answer += A[i];
	}
	cout << Answer << endl;
	return 0;
}