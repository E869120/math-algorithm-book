// 隣接リストの作り方はコード 4.5.1 のコメントアウトを参照

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];
int dist[100009];

int main() {
	// 入力
	scanf("%d%d", &N, &M);
	int i;
	for (i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	
	// 各頂点の次数を数える（手順 1.）
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= M; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	
	// 隣接リスト G の構築（手順 2.）
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	
	// G に辺の情報を追加していく（手順 3.）
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	
	// キュー Q の定義
	// キューの中身が Q[QL], Q[QL+1], ..., Q[QR-1] になるようにする
	// （詳しい原理は https://qiita.com/square1001/items/6d414167ca95c97bd8b2 の 5 節を参照）
	int Q[100009];
	int QL = 0, QR = 0;
	
	// 幅優先探索の初期化（dist[i] = -1 のとき、未到達の白色頂点である）
	for (i = 1; i <= N; i++) {
		dist[i] = -1;
	}
	dist[1] = 0;
	Q[QR] = 1; QR++; // Q に 1 を追加（操作 1）
	
	// 幅優先探索
	while (QL != QR) {
		int pos = Q[QL]; // Q の先頭を調べる（操作 2）
		QL++; // Q の先頭を取り出す（操作 3）
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q[QR] = nex; QR++; // Q に nex を追加（操作 1）
			}
		}
	}
	
	// 頂点 1 から各頂点までの最短距離を出力
	for (i = 1; i <= N; i++) {
		printf("%d\n", dist[i]);
	}
	
	// 隣接リスト G の削除
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}