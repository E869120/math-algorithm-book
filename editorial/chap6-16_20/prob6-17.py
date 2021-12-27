# 入力
N = int(input())

# 縦の長さを 1 から √N まで全探索
LIMIT = int(N ** 0.5)
answer = 10 ** 19
for i in range(1, LIMIT + 1):
	if N % i == 0:
		answer = min(answer, 2 * i + 2 * (N // i))

# 答えの出力
print(answer)