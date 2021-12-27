# 入力
N, X = map(int, input().split())

# すべての (a, b, c) の組み合わせを試す
answer = 0
for a in range(1, N + 1):
	for b in range(a + 1, N + 1):
		for c in range(b + 1, N + 1):
			if a + b + c == X:
				answer += 1

# 答えの出力
print(answer)