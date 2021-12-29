#include <iostream>
#include <set>
using namespace std;
 
// f(m) としてあり得る候補
// set 型についてはインターネットで調べてみてください！
set<long long> fm_cand;
 
// m の各桁の積を返す関数
long long product(long long m) {
	if (m == 0) {
		return 0;
	}
	else {
		long long ans = 1;
		while (m >= 1) {
			ans *= (m % 10);
			m /= 10;
		}
		return ans;
	}
}

void func(int digit, long long m) {
	// m の桁数は 11 桁以下
	// 注：余った桁を 1 で埋めれば、全部 11 桁と仮定しても良い
	if (digit == 11) {
		fm_cand.insert(product(m));
		return;
	}
	
	// 次の桁を探索
	// min_value は cur の最後の桁（単調増加にするためには次の桁がそれ以上でなければならない）
	int min_value = (m % 10);
	for (int i = min_value; i <= 9; i++) {
		// 10 * m + i は m の後ろに数字 i を付けたもの
		func(digit + 1, 10 * m + i);
	}
}
 
int main() {
	// f(m) の候補を列挙
	func(0, 0);
 
	// 入力
	long long N, B;
	cin >> N >> B;
 
	// m - f(m) == B になるかどうかチェック
	long long Answer = 0;
	for (long long fm : fm_cand) {
		long long m = fm + B;
		long long prod_m = product(m);
		if (m - prod_m == B && m <= N) {
			Answer += 1;
		}
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}