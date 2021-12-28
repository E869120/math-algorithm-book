#include <iostream>
using namespace std;

int N;
double A[109], B[109];
double Answer = 0.0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	
	// 期待値を求める
	for (int i = 1; i <= N; i++) {
		double eval = A[i] * (1.0 / 3.0) + B[i] * (2.0 / 3.0);
		Answer += eval;
	}
	
	// 出力
	printf("%.12lf\n", Answer);
	return 0;
}