# 入力
N, X, Y = map(int, input().split())

# 答えを求める
cnt = 0
for i in range(1, N + 1):
	# mod の計算は 2.2 節参照
	if i % X == 0 or i % Y == 0:
		cnt += 1

# 出力
print(cnt)
