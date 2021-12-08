#include <iostream>
using namespace std;

int func(int N) {
	if (N == 1) return 1; // このような場合分けすべきケースを「ベースケース」といいます
	return func(N - 1) * N;
}

int main() {
	int N;
	cin >> N;
	cout << func(N) << endl;
	return 0;
}