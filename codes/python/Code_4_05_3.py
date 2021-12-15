import queue

# 入力
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 隣接リストの作成
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 幅優先探索の初期化 (dist[i] = -1 のとき、未到達の白色頂点である）
dist = [ -1 ] * (N + 1)
Q = queue.Queue()
dist[1] = 0
Q.put(1) # Q に 1 を追加（操作 1）

# 幅優先探索
while not Q.empty():
	pos = Q.get() # Q の先頭を調べ、これを取り出す（操作 2, 3）
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.put(nex) # Q に nex を追加（操作 1）

# 頂点 1 から各頂点までの最短距離を出力
for i in range(1, N + 1):
	print(dist[i])
