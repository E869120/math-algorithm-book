#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009]; // visited[pos]=false のとき頂点 x が白色、true のとき灰色

void dfs(int pos) {
	visited[pos] = true;
	// for (int i : G[pos]) のような書き方を「範囲 for 文」といいます。（APG4b 2.01 節）
	for (int i : G[pos]) {
		if (visited[i] == false) dfs(i);
	}
}

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 深さ優先探索
	dfs(1);

	// 連結かどうかの判定（Answer=true のとき連結）
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) cout << "The graph is connected." << endl;
	else cout << "The graph is not connected." << endl;
	return 0;
}
