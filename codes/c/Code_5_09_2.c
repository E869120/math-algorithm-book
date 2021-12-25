#include <stdio.h>
#include <stdbool.h>

int N, L[2009], R[2009];

int main() {
	// 入力
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &L[i], &R[i]);
	}

	// 映画の選び方のシミュレーション
	// 見れる映画の終了時刻の最小値 min_endtime は最初 1000000 のようなあり得ない値に設定する
	int answer = 0;
	int current_time = 0; // Current_Time は現在時刻（直前に見た映画の終了時刻）
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < current_time) {
				continue;
			}
			if (min_endtime > R[i]) {
				min_endtime = R[i];
			}
		}
		if (min_endtime == 1000000) {
			break;
		}
		current_time = min_endtime;
		answer += 1;
	}

	// 答えの出力
	printf("%d\n", answer);
	return 0;
}
