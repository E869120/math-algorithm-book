#include <stdio.h>
#include <stdbool.h>
 
long long N, K;
long long A[200009];
long long First[200009], Second[200009];
 
int main() {
	// 入力
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 配列の初期化
	for (int i = 1; i <= N; i++) First[i] = -1;
	for (int i = 1; i <= N; i++) Second[i] = -1;
	
	// 答えを求める
	// cur は現在いる町の番号
	long long cnt = 0, cur = 1;
	while (true) {
		// First, Second の更新
		if (First[cur] == -1) First[cur] = cnt;
		else if (Second[cur] == -1) Second[cur] = cnt;
		
		// K 回の移動後に町 cur にいるかどうかの判定
		if (cnt == K) {
			printf("%lld\n", cur);
			return 0;
		}
		else if (Second[cur] != -1 && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
			printf("%lld\n", cur);
			return 0;
		}
		
		// 位置の更新
		cur = A[cur];
		cnt += 1;
	}
	return 0;
}