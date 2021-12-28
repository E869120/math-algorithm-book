#include <stdio.h>
#include <stdlib.h>

int H, W, sx, sy, gx, gy, start, goal; char c[59][59];

int edges, A[5009], B[5009], degree[2509], cnt[2509];
int* G[2509];
int dist[2509];

int main() {
	// 入力
	scanf("%d%d", &H, &W);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &gx, &gy);
	int i, j;
	for (i = 1; i <= H; i++) {
		scanf("%s", c[i] + 1); // 入力した文字列を c[i][1], c[i][2], ... に格納（1 始まりの添え字）
	}
	start = (sx - 1) * W + sy;
	goal = (gx - 1) * W + gy;
	
	// グラフの辺をリストアップ（edges は現在の辺の数）
	edges = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W - 1; j++) {
			if (c[i][j] == '.' && c[i][j + 1] == '.') {
				edges += 1;
				A[edges] = (i - 1) * W + j; // マス (i, j) の頂点番号
				B[edges] = (i - 1) * W + (j + 1); // マス (i, j + 1) の頂点番号
			}
		}
	}
	for (i = 1; i <= H - 1; i++) {
		for (j = 1; j <= W; j++) {
			if (c[i][j] == '.' && c[i + 1][j] == '.') {
				edges += 1;
				A[edges] = (i - 1) * W + j; // マス (i, j) の頂点番号
				B[edges] = i * W + j; // マス (i + 1, j) の頂点番号
			}
		}
	}
	
	// 隣接リストの作成（~/codes/c/Code_4_5_1.c 参照）
	for (i = 1; i <= H * W; i++) degree[i] = 0;
	for (i = 1; i <= edges; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= H * W; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= H * W; i++) cnt[i] = 0;
	for (i = 1; i <= edges; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// キュー Q の定義 → 幅優先探索の初期化（~/codes/c/Code_4_5_3.c 参照）
	int Q[2509];
	int QL = 0, QR = 0;
	for (i = 1; i <= H * W; i++) {
		dist[i] = -1;
	}
	dist[start] = 0;
	Q[QR] = start; QR++; // Q に start を追加
	
	// 幅優先探索（~/codes/c/Code_4_5_3.c 参照）
	while (QL != QR) {
		int pos = Q[QL]; // Q の先頭を調べる
		QL++; // Q の先頭を取り出す
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q[QR] = nex; QR++; // Q に nex を追加
			}
		}
	}
	
	// 答えを出力
	printf("%d\n", dist[goal]);
	
	return 0;
}
