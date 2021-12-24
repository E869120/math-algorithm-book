#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009];

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	
	// 答えを求める
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 0; j < G[i].size(); j++) {
			// G[i][j] は頂点 i に隣接している頂点のうち j 個目
			if (G[i][j] < i) cnt += 1;
		}
		// 自分自身より小さい隣接頂点が 1 つであれば Answer に 1 を加算する
		if (cnt == 1) Answer += 1;
	}
	
	// 出力
	cout << Answer << endl;
	return 0;
}