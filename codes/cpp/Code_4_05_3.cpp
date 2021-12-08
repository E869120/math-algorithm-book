#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A[100009], B[100009];
int dist[100009];
vector<int> G[100009];

int main() {
	// ����
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// ���D��T���̏������idist[i]=-1 �̂Ƃ��A�����B�̔��F���_�ł���j
	for (int i = 1; i <= N; i++) dist[i] = -1;
	queue<int> Q; // �L���[ Q ���`����
	Q.push(1); dist[1] = 0; // Q �� 1 ��ǉ��i���� 1�j

	// ���D��T��
	while (!Q.empty()) {
		int pos = Q.front(); // Q �̐擪�𒲂ׂ�i���� 2�j
		Q.pop(); // Q �̐擪�����o���i���� 3�j
		for (int i = 0; i < (int)G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex); // Q �� nex ��ǉ��i���� 1�j
			}
		}
	}

	// ���_ 1 ����e���_�܂ł̍ŒZ�������o��
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	return 0;
}