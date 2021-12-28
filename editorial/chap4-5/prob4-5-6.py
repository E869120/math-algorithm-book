# このプログラムは、c[i-1][j-1] がマス (i, j) を指すように実装しています。
# マス (i, j) の頂点番号は i * W + j とすると、頂点番号 0, 1, 2, ..., HW-1 の頂点が 1 個ずつになります。

import queue

# 入力
H, W = map(int, input().split())
sx, sy = map(int, input().split())
gx, gy = map(int, input().split())
c = [ input() for i in range(H) ]
start = (sx - 1) * W + (sy - 1)
goal = (gx - 1) * W + (gy - 1)

# 隣接リストの作成
G = [ list() for i in range(H * W) ]

# 横方向の辺 [(i, j) - (i, j+1)] をグラフに追加
for i in range(H):
	for j in range(W - 1):
		if c[i][j] == "." and c[i][j + 1] == ".":
			idx1 = i * W + j  # マス (i, j) の頂点番号
			idx2 = i * W + (j + 1)  # マス (i, j + 1) の頂点番号
			G[idx1].append(idx2)
			G[idx2].append(idx1)

# 縦方向の辺 [(i, j) - (i+1, j)] をグラフに追加
for i in range(H - 1):
	for j in range(W):
		if c[i][j] == "." and c[i + 1][j] == ".":
			idx1 = i * W + j  # マス (i, j) の頂点番号
			idx2 = (i + 1) * W + j  # マス (i + 1, j) の頂点番号
			G[idx1].append(idx2)
			G[idx2].append(idx1)

# 幅優先探索の初期化 (dist[i] = -1 のとき、未到達の白色頂点である）
dist = [ -1 ] * (H * W)
Q = queue.Queue()
dist[start] = 0
Q.put(start) # Q に start を追加

# 幅優先探索
while not Q.empty():
	pos = Q.get() # Q の先頭を調べ、これを取り出す
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.put(nex) # Q に nex を追加

# 答えを出力
print(dist[goal])
