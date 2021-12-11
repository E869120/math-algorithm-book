# 入力
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 全パターンを探索：(1 << N) は 2 の N 乗
answer = "No"
for i in range(0, 1 << N):
	partsum = 0
	for j in range(0, N):
		# (i & (1 << j)) != 0LL の場合、i の 2 進法表記の下から j+1 桁目が 1
		# (1 << j) は Python では「2 の j 乗」を意味します
		if (i & (1 << j)) != 0:
			partsum += A[j]
	if partsum == S:
		answer = "Yes"
		break

# 出力
print(answer)
