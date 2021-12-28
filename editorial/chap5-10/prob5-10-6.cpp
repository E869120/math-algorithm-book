#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
// f(m) としてあり得る候補
vector<long long> fm_cand;
 
// m の総積を返す関数
long long product(long long m) {
	string str = to_string(m); // 整数 m を文字列に変換
	long long ans = 1;
	for (int i = 0; i < str.size(); i++) {
		ans *= (long long)(str[i] - '0');
	}
	return ans;
}
 
void func(int digit, string cur) {
	// m の桁数は 11 桁以下
	long long m = stoll(cur);
	fm_cand.push_back(product(m));
	if (digit == 11) return;
 
	// 次の桁を探索
	// min_value は cur の最後の桁（単調増加にするためには次の桁がそれ以上でなければならない）
	int min_value = (cur[cur.size() - 1] - '0');
	for (int i = min_value; i <= 9; i++) {
		string cur_next = cur;
		cur_next += ('0' + i);
		func(digit + 1, cur_next);
	}
}
 
int main() {
	// f(m) の候補を列挙
	for (int i = 0; i <= 9; i++) {
		string cur = ""; cur += ('0' + i);
		func(1, cur);
	}
 
	// fm_cand の重複要素を取り除く操作
	// erase とか unique とか難しいので、ここはそういうものだと思っておけば良い
	sort(fm_cand.begin(), fm_cand.end());
	fm_cand.erase(unique(fm_cand.begin(), fm_cand.end()), fm_cand.end());
 
	// 入力
	long long N, B;
	cin >> N >> B;
 
	// m の総積が f(m) になるかどうかチェック
	long long Answer = 0;
	for (int i = 0; i < fm_cand.size(); i++) {
		long long m = fm_cand[i] + B;
		long long prod_m = product(m);
		if (prod_m == fm_cand[i] && m <= N) {
			Answer += 1;
		}
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}