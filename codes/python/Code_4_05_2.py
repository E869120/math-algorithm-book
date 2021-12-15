import sys

# 深さ優先探索を行う関数
def dfs(pos, G, visited):
	visited[pos] = True
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited)

# 再帰呼び出しの深さの上限を 120000 に設定
sys.setrecursionlimit(120000)

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

# 深さ優先探索
visited = [ False ] * (N + 1)
dfs(1, G, visited)

# 連結かどうかの判定（answer = true のとき連結）
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")
