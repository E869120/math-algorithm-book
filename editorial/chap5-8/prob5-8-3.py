# 本プログラムを Python で提出すると、比較的処理が遅くなるため実行時間制限オーバー (TLE) となります。
# PyPy3 で提出すると、正解 (AC) することができます。

import heapq

# 入力
N, M = map(int, input().split())
A, B, C = [ None ] * M, [ None ] * M, [ None ] * M
for i in range(M):
	A[i], B[i], C[i] = map(int, input().split())

# 隣接リストの作成 → グラフの辺を追加
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append((B[i], C[i]))
	G[B[i]].append((A[i], C[i]))

# ダイクストラ法：配列の初期化など
dist = [ 10 ** 19 ] * (N + 1)
used = [ False ] * (N + 1)
Q = list()
dist[1] = 0
heapq.heappush(Q, (0, 1))

# ダイクストラ法：優先度付きキューの更新
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if used[pos] == True:
		continue
	used[pos] = True
	for i in G[pos]:
		to = i[0]
		cost = dist[pos] + i[1]
		if dist[to] > cost:
			dist[to] = cost
			heapq.heappush(Q, (dist[to], to))

# 答えを出力
if dist[N] != 10 ** 19:
	print(dist[N])
else:
	print(-1)