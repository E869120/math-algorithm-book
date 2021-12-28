import sys

# 深さ優先探索を行う関数
def dfs(pos, G, color):
	for i in G[pos]:
		if color[i] == 0:
			# color[pos] = 1 のとき 2、color[pos] = 2 のとき 1
			color[i] = 3 - color[pos]
			dfs(i, G, color)

# 再帰呼び出しの深さの上限を 210000 に設定
sys.setrecursionlimit(210000)

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
color = [ 0 ] * (N + 1)
for i in range(1, N + 1):
	if color[i] == 0:
		# 頂点 i は白である（まだ探索されていない連結成分である）
		color[i] = 1
		dfs(i, G, color)

# 二部グラフかどうかの判定
answer = True
for i in range(M):
	if color[A[i]] == color[B[i]]:
		answer = False
if answer == True:
	print("Yes")
else:
	print("No")
