#include <iostream>
#include <algorithm>
using namespace std;

int N, L[2009], R[2009];
int Current_Time = 0, Answer = 0; // Current_Time は現在時刻（直前に見た映画の終了時刻）

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 映画の選び方のシミュレーション
	// 見れる映画の終了時刻の最小値 min_endtime は最初 1000000 のようなあり得ない値に設定する
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < Current_Time) continue;
			min_endtime = min(min_endtime, R[i]);
		}
		if (min_endtime == 1000000) break;
		Current_Time = min_endtime;
		Answer += 1;
	}

	// 答えの出力
	cout << Answer << endl;
	return 0;
}