#include <iostream>
using namespace std;

bool isprime(int x) {
	for (int i = 2; i <= x - 1; i++) {
		// x を i で割った余りが 0 のとき、x は i で割り切れる
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	// 入力
	int N;
	cin >> N;
	
	// 答えの出力（空白区切りで出力する場合）
	for (int i = 2; i <= N; i++) {
		if (isprime(i) == true) {
			if (i >= 3) cout << " ";
			cout << i;
		}
	}
	cout << endl;
	return 0;
}