#include <iostream>
using namespace std;

long long cross(long long ax, long long ay, long long bx, long long by) {
	// ベクトル (ax, ay) と (bx, by) の外積の大きさ
	return ax * by - ay * bx;
}

int main() {
	// 入力
	long long X1, Y1, X2, Y2, X3, Y3, X4, Y4;
	cin >> X1 >> Y1; // 点 A の座標を入力
	cin >> X2 >> Y2; // 点 B の座標を入力
	cin >> X3 >> Y3; // 点 C の座標を入力
	cin >> X4 >> Y4; // 点 D の座標を入力
	
	// cross(AB, AC) を計算
	long long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
	long long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
	long long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
	long long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
	
	// すべて一直線上に並んでいる場合（コーナーケース）
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		// A, B, C, D を数値（正確には pair 型）とみなす
		// 適切に swap することで A<B, C<D を仮定できる
		// そうすると、区間が重なるかの判定（節末問題 2.5.6）に帰着できる
		pair<long long, long long> A = make_pair(X1, Y1);
		pair<long long, long long> B = make_pair(X2, Y2);
		pair<long long, long long> C = make_pair(X3, Y3);
		pair<long long, long long> D = make_pair(X4, Y4);
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		if (max(A, C) <= min(B, D)) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	
	// そうでない場合
	// IsAB: 線分 AB が点 C, D を分けるか？
	// IsCD: 線分 CD が点 A, B を分けるか？
	bool IsAB = false, IsCD = false;
	if (ans1 >= 0 && ans2 <= 0) IsAB = true;
	if (ans1 <= 0 && ans2 >= 0) IsAB = true;
	if (ans3 >= 0 && ans4 <= 0) IsCD = true;
	if (ans3 <= 0 && ans4 >= 0) IsCD = true;
	
	// 答えの出力
	if (IsAB == true && IsCD == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}