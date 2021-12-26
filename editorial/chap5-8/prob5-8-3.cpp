#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long A[500009], B[500009], C[500009];

// グラフ
bool used[500009];
long long dist[500009]; // 最短経路長
vector<pair<int, long long>> G[500009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
 
// ダイクストラ法
void dijkstra() {
	// 配列の初期化など
	for (int i = 1; i <= N; i++) dist[i] = (1LL << 60);
	for (int i = 1; i <= M; i++) used[i] = false;
	dist[1] = 0;
	Q.push(make_pair(0, 1));

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
	// 入力・グラフの辺の追加
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(make_pair(B[i], C[i]));
		G[B[i]].push_back(make_pair(A[i], C[i]));
	}
	
	// ダイクストラ法
	dijkstra();
	
	// 答えの出力
	if (dist[N] == (1LL << 60)) cout << "-1" << endl;
	else cout << dist[N] << endl;
	return 0;
}