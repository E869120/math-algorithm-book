#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009]; // visited[pos]=false �̂Ƃ����_ x �����F�Atrue �̂Ƃ��D�F

void dfs(int pos) {
	visited[pos] = true;
	for (int i : G[pos]) {
		if (visited[i] == false) dfs(i);
	}
}

int main() {
	// ����
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// �[���D��T��
	dfs(1);

	// �A�����ǂ����̔���iAnswer=true �̂Ƃ��A���j
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) cout << "The graph is connected." << endl;
	else cout << "The graph is not connected." << endl;
	return 0;
}