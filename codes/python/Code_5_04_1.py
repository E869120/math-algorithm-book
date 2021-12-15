# 入力
N, K = map(int, input().split())

# 事象 B の個数 yojishou を数える
yojishou = 0
for a in range(1, N + 1):
	l = max(1, a - (K - 1)) # b, c の探索範囲の下限 l
	r = min(N, a + (K - 1)) # b, c の探索範囲の上限 r
	for b in range(l, r + 1):
		for c in range(l, r + 1):
			if abs(b - c) <= K - 1:
				yojishou += 1

# 答えの出力
print(N ** 3 - yojishou)
