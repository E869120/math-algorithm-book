// 隣接リストの作り方はコード 4.5.1 のコメントアウトを参照

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

bool visited[100009];

void dfs(int pos) {
	visited[pos] = true;
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (visited[G[pos][i]] == false) {
			dfs(G[pos][i]);
		}
	}
}

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
	
	// 深さ優先探索
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	dfs(1);
	
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
