#include <iostream>
using namespace std;
 
long long N, K;
long long V[20];
long long Answer = 0;
 
// 最大公約数を返す関数
long long GCD(long long A, long long B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}
 
// 最小公倍数を返す関数
long long LCM(long long A, long long B) {
	return (A / GCD(A, B)) * B;
}
 
int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> V[i];
 
	// ビット全探索
	for (int i = 1; i < (1 << K); i++) {
		long long cnt = 0; // 選んだ数の個数
		long long lcm = 1; // 最小公倍数
		for (int j = 0; j < K; j++) {
			if ((i & (1 << j)) != 0) {
				cnt += 1;
				lcm = LCM(lcm, V[j + 1]);
			}
		}
		long long num = N / lcm; // 選ばれた数すべての倍数であるものの個数
		if (cnt % 2 == 1) Answer += num;
		if (cnt % 2 == 0) Answer -= num;
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}