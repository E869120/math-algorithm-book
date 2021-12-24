#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// 入力
int H, W;
int sx, sy, start; // スタートの座標 (sx, sy) と頂点番号 sx*H+sy
int gx, gy, goal;  // ゴールの座標 (gx, gy) と頂点番号 gx*W+gy
char c[59][59];
 
// グラフ・最短経路
int dist[2509];
vector<int> G[2509];
 
int main() {
	// 入力
	cin >> H >> W;
	cin >> sx >> sy; start = sx * W + sy;
	cin >> gx >> gy; goal = gx * W + gy;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	
	// 横方向の辺 [(i, j) - (i, j+1)] をグラフに追加
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W - 1; j++) {
			int idx1 = i * W + j; // 頂点 (i, j) の頂点番号
			int idx2 = i * W + (j+1); // 頂点 (i, j+1) の頂点番号
			if (c[i][j] == '.' && c[i][j+1] == '.'){
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}
	
	// 縦方向の辺 [(i, j) - (i+1, j)] をグラフに追加
	for (int i = 1; i <= H - 1; i++) {
		for (int j = 1; j <= W; j++) {
			int idx1 = i * W + j; // 頂点 (i, j) の頂点番号
			int idx2 = (i+1) * W + j; // 頂点 (i+1, j) の頂点番号
			if (c[i][j] == '.' && c[i+1][j] == '.'){
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}
 
	// 幅優先探索の初期化（dist[i]=-1 のとき、未到達の白色頂点である）
	for (int i = 1; i <= H * W; i++) dist[i] = -1;
	queue<int> Q; // キュー Q を定義する
	Q.push(start); dist[start] = 0; // Q に 1 を追加（操作 1）
 
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
 
	// 答えを出力
	cout << dist[goal] << endl;
	return 0;
}