#include <stdio.h>

int N, K; long long X[59], Y[59];

int check_numpoints(long long lx, long long rx, long long ly, long long ry) {
	int cnt = 0;
	int i;
	for (i = 1; i <= N; i++) {
		// 点 (X[i], Y[i]) が長方形に含まれているかどうかを判定する
		if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) {
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	// 入力
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]);
	}

	// 左端 x、右端 x、下端 y、上端 y を全探索（それぞれの番号が i, j, k, l）
	long long answer = (1LL << 62); // あり得ない値に設定
	int i, j, k, l;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				for (l = 1; l <= N; l++) {
					long long cl = X[i]; // 左端の x 座標
					long long cr = X[j]; // 右端の x 座標
					long long dl = Y[k]; // 下端の y 座標
					long long dr = Y[l]; // 上端の y 座標
					if (check_numpoints(cl, cr, dl, dr) >= K) {
						long long area = (cr - cl) * (dr - dl);
						if (answer > area) {
							answer = area;
						}
					}
				}
			}
		}
	}

	// 答えの出力
	printf("%lld\n", answer);
	return 0;
}
