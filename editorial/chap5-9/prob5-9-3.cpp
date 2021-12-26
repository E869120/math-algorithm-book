#include <iostream>
#include <algorithm>
using namespace std;
 
// Movie 型
struct Movie {
	int l, r;
};
 
bool operator<(const Movie &a1, const Movie &a2) {
	if (a1.r < a2.r) return true;
	if (a1.r > a2.r) return false;
	if (a1.l < a2.l) return true;
	return false;
}
 
int N;
Movie A[300009];
int CurrentTime = 0; // 現在時刻（最後に選んだ映画の終了時刻）
int Answer = 0; // 現在見た映画の数
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i].l >> A[i].r;
	
	// ソート
	sort(A + 1, A + N + 1);
	
	// 終了時刻が最も早いものを選び続ける
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= A[i].l) {
			CurrentTime = A[i].r;
			Answer += 1;
		}
	}
	
	// 出力
	cout << Answer << endl;
	return 0;
}