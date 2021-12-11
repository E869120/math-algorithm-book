# 入力
N, S = map(int, input().split())

# 答えを求める
answer = 0
for i in range(1, N + 1):
	for j in range(1, N + 1):
		if i + j <= S:
			answer += 1

# 出力
print(answer)
