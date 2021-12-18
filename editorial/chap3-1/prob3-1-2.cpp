#include <iostream>
using namespace std;

int main() {
	// 入力
	long long N;
	cin >> N;
	
	// 素因数分解（空白区切りで出力）
	bool flag = false;
	for (long long i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			if (flag == true) cout << " ";
			flag = true;
			N /= i;
			cout << i;
		}
	}
	if (N >= 2) {
		if (flag == true) cout << " ";
		flag = true;
		cout << N;
	}
	cout << endl;
	return 0;
}