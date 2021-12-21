#include <iostream>
#include <cmath>
using namespace std;
 
double X1, Y1, R1;
double X2, Y2, R2;
 
int main() {
	// 入力
	cin >> X1 >> Y1 >> R1;
	cin >> X2 >> Y2 >> R2;
	
	// 円の中心間距離を求める
	double d = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
	
	// 答えを出力
	if (d < abs(R1 - R2)) cout << "1" << endl;
	else if (d == abs(R1 - R2)) cout << "2" << endl;
	else if (d < R1 + R2) cout << "3" << endl;
	else if (d == R1 + R2) cout << "4" << endl;
	else cout << "5" << endl;
	return 0;
}