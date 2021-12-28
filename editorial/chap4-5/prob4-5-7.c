#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[200009], B[200009]; // N, M ≦ 200000 なので配列の大きさは 200009 にしておく
int degree[200009], cnt[200009];
int* G[200009];

int color[200009];

void dfs(int pos) {
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (color[G[pos][i]] == 0) {
			// color[pos] = 1 のとき 2、color[pos] = 2 のとき 1
			color[G[pos][i]] = 3 - color[pos];
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
	
	// 隣接リストの作成（~/codes/c/Code_4_5_1.c 参照）
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= M; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 深さ優先探索
	for (i = 1; i <= N; i++) {
		color[i] = 0;
	}
	for (i = 1; i <= N; i++) {
		if (color[i] == 0) {
			// 頂点 i は白である（まだ探索されていない連結成分である）
			color[i] = 1;
			dfs(i);
		}
	}
	
	// 二部グラフかどうかの判定
	bool answer = true;
	for (i = 1; i <= M; i++) {
		if (color[A[i]] == color[B[i]]) {
			answer = false;
		}
	}
	if (answer == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	
	return 0;
}
