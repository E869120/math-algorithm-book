#include <iostream>
#include <cmath>
using namespace std;

int N;
double x[2009], y[2009];
double Answer = 1000000000.0; // 非常に大きい値に初期化

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
	
	// 全探索
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// dist は i 番目の点と j 番目の点の距離
			double dist = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
			Answer = min(Answer, dist);
		}
	}
	
	// 答えの出力
	printf("%.12lf¥n", Answer);
	return 0;
}