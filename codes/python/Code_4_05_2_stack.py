# このソースコードは、深さ優先探索 (DFS) をスタックを用いて実装したものです。
# スタックは「一番上に要素を積む」「一番上の要素を調べる」「一番上に積まれた要素を取り除く」という 3 種類の操作ができるデータ構造です。
# 深さ優先探索の部分は、コード 4.5.3 のキューをスタックに変更したものをベースに書かれています。

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

# 深さ優先探索の初期化
visited = [ False ] * (N + 1)
S = list() # スタック S を定義
visited[1] = True
S.append(1) # S に 1 を追加

# 深さ優先探索
while len(S) >= 1:
	pos = S.pop() # S の先頭を調べ、これを取り出す
	for nex in G[pos]:
		if visited[nex] == False:
			visited[nex] = True
			S.append(nex) # S に nex を追加

# 連結かどうかの判定（answer = true のとき連結）
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")