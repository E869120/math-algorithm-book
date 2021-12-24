#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[200009], B[200009]; // N, M ≦ 200000 なので配列の大きさは 200009 にしておく
vector<int> G[200009];
int color[200009];

void dfs(int pos) {
	for (int i : G[pos]) { // 範囲 for 文
		if (color[i] == 0) {
			// color[pos]=1 のとき 2、color[pos]=2 のとき 1
			color[i] = 3 - color[pos];
			dfs(i);
		}
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
	for (int i = 1; i <= N; i++) color[i] = 0;
	for (int i = 1; i <= N; i++) {
		if (color[i] == 0) {
			// 頂点 i は白である（まだ探索されていない連結成分である）
			color[i] = 1;
			dfs(i);
		}
	}
	
	// 二部グラフかどうかの判定
	bool Answer = true;
	for (int i = 1; i <= M; i++) {
		if (color[A[i]] == color[B[i]]) Answer = false;
	}
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}