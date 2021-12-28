import heapq

# 入力
K = int(input())

# 隣接リストの作成 → グラフの辺を追加
G = [ list() for i in range(K) ]
for i in range(K):
	for j in range(10):
		if i == 0 and j == 0:
			continue
		G[i].append(((i * 10 + j) % K, j))

# ダイクストラ法：配列の初期化など
dist = [ 10 ** 10 ] * K
used = [ False ] * K
Q = list()
heapq.heappush(Q, (0, 0))  # ここでは dist[0] = 0 にはしないことに注意！

# ダイクストラ法：優先度付きキューの更新
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if used[pos] == True:
		continue
	used[pos] = True
	for i in G[pos]:
		to = i[0]
		cost = dist[pos] + i[1]
		if pos == 0:
			cost = i[1]  # 頂点 0 の場合は例外
		if dist[to] > cost:
			dist[to] = cost
			heapq.heappush(Q, (dist[to], to))

# 答えを出力
print(dist[0])
