# 入力
N = int(input())
A = list(map(int, input().split()))

# 答えを求める
answer = 0
for i in range(N):
	# コード 5.7.1 (C++) では A[i] * (-N + 2 * i - 1) となっていますが、ここでは i = 0 から始まるので -N + 2 * i + 1 が掛けられます。
	answer += A[i] * (-N + 2 * i + 1)

# 答えの出力
print(answer)
