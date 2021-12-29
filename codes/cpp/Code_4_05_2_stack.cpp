// このソースコードは、深さ優先探索 (DFS) をスタックを用いて実装したものです。
// スタックは「一番上に要素を積む」「一番上の要素を調べる」「一番上に積まれた要素を取り除く」という 3 種類の操作ができるデータ構造です。
// 深さ優先探索の部分は、コード 4.5.3 の queue を stack に変更したものをベースに書かれています。

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 深さ優先探索の初期化
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	stack<int> S; // スタック S を定義する
	visited[1] = true;
	S.push(1); // S に 1 を追加

	// 深さ優先探索
	while (!S.empty()) {
		int pos = S.top(); // S の先頭を調べる
		S.pop(); // S の先頭を取り出す
		for (int nex : G[pos]) {
			if (visited[nex] == false) {
				visited[nex] = true;
				S.push(nex); // S に nex を追加
			}
		}
	}

	// 連結かどうかの判定（Answer=true のとき連結）
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) {
		cout << "The graph is connected." << endl;
	}
	else {
		cout << "The graph is not connected." << endl;
	}
	return 0;
}