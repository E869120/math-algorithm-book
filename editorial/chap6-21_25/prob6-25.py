import sys

# 深さ優先探索を行う関数
def dfs(pos, G, visited, dp):
	visited[pos] = True
	dp[pos] = 1
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited, dp)
			dp[pos] += dp[i]

# 再帰呼び出しの深さの上限を 120000 に設定
sys.setrecursionlimit(120000)

# 入力
N = int(input())
A = [ None ] * (N - 1)
B = [ None ] * (N - 1)
for i in range(N - 1):
	A[i], B[i] = map(int, input().split())

# 隣接リストの作成
G = [ list() for i in range(N + 1) ]
for i in range(N - 1):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 深さ優先探索 (DFS) を使った動的計画法
visited = [ False ] * (N + 1)
dp = [ None ] * (N + 1)
dfs(1, G, visited, dp)

# 答えを計算して出力
answer = 0
for i in range(2, N + 1):
	answer += dp[i] * (N - dp[i])
print(answer)