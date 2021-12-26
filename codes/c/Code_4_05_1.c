// C 言語ではコード 4.5.1 の vector<int> に相当するものが使えないので、本コードでは以下の 3 ステップでグラフの隣接リストを構築しています。
// 手順 1. 各頂点の次数 degree[i] を数える
// 手順 2. 各 G[i] のメモリを malloc で動的確保する
// 手順 3. 確保された G[i] に辺の行き先を割り当てていく

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
	
	// 出力
	for (i = 1; i <= N; i++) {
		printf("%d: {", i);
		for (j = 0; j < degree[i]; j++) {
			if (j >= 1) printf(","); // コンマ区切りで出力する
			printf("%d", G[i][j]); // G[i][j] は頂点 i に隣接する頂点のうち j 番目のもの
		}
		printf("}\n");
	}
	
	// 隣接リスト G の削除
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}
