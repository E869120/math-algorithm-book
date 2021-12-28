import sys

# 入力
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 配列の初期化
First = [-1 for i in range(N+1)]
Second = [-1 for i in range(N+1)]

# 答えを求める
# cur は現在いる町の番号
cnt = 0
cur = 1
while True:
	# First, Second の更新
	if First[cur] == -1:
		First[cur] = cnt
	elif Second[cur] == -1:
		Second[cur] = cnt
	
	# K 回の移動後に町 cur にいるか判定
	if cnt == K:
		print(cur)
		sys.exit()
	elif Second[cur] != -1 and (K - First[cur]) % (Second[cur] - First[cur]) == 0:
		print(cur)
		sys.exit()
	
	cur = A[cur - 1]
	cnt += 1