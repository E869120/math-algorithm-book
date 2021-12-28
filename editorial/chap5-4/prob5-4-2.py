# 入力
H, W = map(int, input().split())
A = [[] for i in range(H)]
for i in range(H):
	A[i] = list(map(int, input().split()))

# 行の総和を計算する
gyou = [0 for i in range(H)]
for i in range(H):
	for j in range(W):
		gyou[i] += A[i][j]

# 列の総和を計算する
retu = [0 for i in range(W)]
for j in range(W):
	for i in range(H):
		retu[j] += A[i][j]

# 各マスに対する答えを計算する
Answer = [[0 for j in range(W)] for i in range(H)]
for i in range(H):
	for j in range(W):
		Answer[i][j] = gyou[i] + retu[j] - A[i][j]

# 出力
for i in range(H):
	print(*Answer[i])