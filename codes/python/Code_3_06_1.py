# 入力（たとえば N = 5, A = [3, 1, 4, 1, 5] を入力したとする）
N = int(input())
A = list(map(int, input().split()))

# 配列 A 全体をソートする
A.sort()

# 出力（1, 1, 3, 4, 5 の順に出力される）
for i in range(N):
	print(A[i])
