#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A[100009], B[100009];
int dist[100009];
vector<int> G[100009];

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 幅優先探索の初期化（dist[i]=-1 のとき、未到達の白色頂点である）
	for (int i = 1; i <= N; i++) dist[i] = -1;
	queue<int> Q; // キュー Q を定義する
	Q.push(1); dist[1] = 0; // Q に 1 を追加（操作 1）

	// 幅優先探索
	while (!Q.empty()) {
		int pos = Q.front(); // Q の先頭を調べる（操作 2）
		Q.pop(); // Q の先頭を取り出す（操作 3）
		for (int i = 0; i < (int)G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex); // Q に nex を追加（操作 1）
			}
		}
	}

	// 頂点 1 から各頂点までの最短距離を出力
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	return 0;
}