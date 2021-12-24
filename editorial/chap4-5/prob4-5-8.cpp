#include <bits/stdc++.h>
using namespace std;
 
int K, dist[1 << 18];
bool used[1 << 18];
vector<pair<int, int>> G[1 << 18];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
 
// ダイクストラ法
void dijkstra() {
	// 配列の初期化など
	for (int i = 0; i < K; i++) dist[i] = (1 << 30);
	for (int i = 0; i < K; i++) used[i] = false;
	Q.push(make_pair(0, 0)); // ここでdist[0] = 0 にはしないことに注意！

	// キューの更新
	while (!Q.empty()) {
		int pos = Q.top().second; Q.pop();
		if (used[pos] == true) continue;
		used[pos] = true;
		for (pair<int, int> i : G[pos]) {
			int to = i.first, cost = dist[pos] + i.second;
			if (pos == 0) cost = i.second; // 頂点 0 の場合は例外
			if (dist[to] > cost) {
				dist[to] = cost;
				Q.push(make_pair(dist[to], to));
			}
		}
	}
}
 
int main() {
	// 入力
	cin >> K;
	
	// グラフの辺を追加
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) continue;
			G[i].push_back(make_pair((i * 10 + j) % K, j));
		}
	}
	
	// ダイクストラ法・出力
	dijkstra();
	cout << dist[0] << endl;
	return 0;
}