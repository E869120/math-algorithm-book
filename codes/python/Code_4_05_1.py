# 入力
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 隣接リストの作成
G = [ list() for i in range(N + 1) ] # G[i] は頂点 i に隣接する頂点のリスト
for i in range(M):
	G[A[i]].append(B[i]) # 頂点 A[i] に隣接する頂点として B[i] を追加
	G[B[i]].append(A[i]) # 頂点 B[i] に隣接する頂点として A[i] を追加

# 出力（len(G[i]) は頂点 i に隣接する頂点のリストの大きさ ＝ 次数）
for i in range(1, N + 1):
	output = str(i) + ": {"
	for j in range(len(G[i])):
		if j >= 1:
			output += ","
		output += str(G[i][j]) # G[i][j] は頂点 i に隣接する頂点のうち j+1 番目のもの
	output += "}"
	print(output)
