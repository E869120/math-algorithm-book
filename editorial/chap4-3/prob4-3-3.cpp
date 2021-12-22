#include <iostream>
using namespace std;

int main() {
	double l = 1.0; // √2 を求めたいから
	double r = 2.0; // 初期値を適当に 2.0 にセットする
	
	for (int i = 1; i <= 20; i++) {
		double m = (l + r) / 2.0;
		if (m * m < 2.0) l = m;
		else r = m;
		printf("Step #%d: m = %.12lf¥n", i, m);
	}
	return 0;
}