#include <stdio.h>
 
// Movie 型
struct Movie {
	int l, r;
};

// r の小さい方を「小さい」と判定する
int compare_values(const void* a, const void* b) {
	// a の方が前に来るとき 負の値
	// b の方が前に来るとき 正の値
	// a と b が等しい値のとき 0 を返す関数
	struct Movie A = *(const struct Movie*)a;
	struct Movie B = *(const struct Movie*)b;
	if (A.r < B.r) return -1;
	else if (A.r > B.r) return +1;
	return 0;
}

int N;
struct Movie A[300009];
int CurrentTime = 0; // 現在時刻（最後に選んだ映画の終了時刻）
int Answer = 0; // 現在見た映画の数
 
int main() {
	// 入力
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &A[i].l, &A[i].r);
	
	// ソート
	qsort(A + 1, N, sizeof(*A), compare_values);
	
	// 終了時刻が最も早いものを選び続ける
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= A[i].l) {
			CurrentTime = A[i].r;
			Answer += 1;
		}
	}
	
	// 出力
	printf("%d\n", Answer);
	return 0;
}