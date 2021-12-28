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

# 答えを求める
answer = 0
for i in range(1, N + 1):
	cnt = 0
	for j in G[i]:
		if j < i:
			cnt += 1
	# 自分自身より番号が小さい隣接頂点が 1 つであれば answer に 1 を加算する
	if cnt == 1:
		answer += 1

# 答えを出力
print(answer)
