#include <stdio.h>

int main() {
	// 入力
	int N; char S[500009];
	scanf("%d%s", &N, S);

	// '(' の数 - ')' の数を depth とする
	// 途中で depth が負になったらこの時点で No
	int depth = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') depth += 1;
		if (S[i] == ')') depth -= 1;
		if (depth < 0) {
			printf("No\n");
			return 0;
		}
	}

	// 最後、depth = 0 ['(' と ')' の数が同じ] かどうかで場合分け
	if (depth == 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
