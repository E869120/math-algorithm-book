#include <stdio.h>
#include <stdlib.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

int main() {
	// 入力
	scanf("%d%d", &N, &M);
	int i, j;
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
	
	// 答えを求める
	int answer = 0;
	for (i = 1; i <= N; i++) {
		int cnt = 0;
		for (j = 0; j < degree[i]; j++) {
			// G[i][j] は頂点 i に隣接している頂点のうち j+1 個目
			if (G[i][j] < i) {
				cnt += 1;
			}
		}
		// 自分自身より番号が小さい隣接頂点が 1 つであれば Answer に 1 を加算する
		if (cnt == 1) {
			answer += 1;
		}
	}
	
	// 答えを出力
	printf("%d\n", answer);
	
	return 0;
}
