// このソースコードは、深さ優先探索 (DFS) をスタックを用いて実装したものです。
// スタックは「一番上に要素を積む」「一番上の要素を調べる」「一番上に積まれた要素を取り除く」という 3 種類の操作ができるデータ構造です。
// 深さ優先探索の部分は、コード 4.5.3 の queue を stack に変更したものをベースに書かれています。

// 隣接リストの作り方はコード 4.5.1 のコメントを参照

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];
bool visited[100009];

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
	
	
	// スタック S の定義
	// スタックの中身が S[0], S[1], ..., S[SZ - 1] になるようにする
	int S[100009], SZ = 0;
	
	// 深さ優先探索の初期化
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	visited[1] = true;
	S[SZ] = 1; SZ++; // S に 1 を追加
	
	// 幅優先探索
	while (SZ >= 1) {
		int pos = S[SZ - 1]; // S の先頭を調べる
		SZ--; // S の先頭を取り出す
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (visited[nex] == false) {
				visited[nex] = true;
				S[SZ] = nex; SZ++; // S に nex を追加
			}
		}
	}
	
	// 連結かどうかの判定（Answer=true のとき連結）
	bool answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			answer = false;
		}
	}
	if (answer == true) {
		printf("The graph is connected.\n");
	}
	else {
		printf("The graph is not connected.\n");
	}
	
	// 隣接リスト G の削除
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}