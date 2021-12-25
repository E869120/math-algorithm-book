#include <stdio.h>

int N, A[109];

int solve(int l, int r) {
	if (r - l == 1) return A[l];
	int m = (l + r) / 2; // 区間 [l, r) の中央で分割する
	int s1 = solve(l, m); // s1 は A[l]+...+A[m-1] の合計値となる
	int s2 = solve(m, r); // s2 は A[m]+...+A[r-1] の合計値となる
	return s1 + s2;
}

int main() {
	// 入力
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	// 再帰呼び出し → 答えの出力
	int answer = solve(1, N + 1);
	printf("%d\n", answer);
	return 0;
}
