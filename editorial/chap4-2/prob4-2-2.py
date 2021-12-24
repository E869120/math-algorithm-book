# 入力
T = int(input())
N = int(input())
A = [0 for i in range(T + 2)]
B = [0 for i in range(T + 2)]
L = [0 for i in range(N)]
R = [0 for i in range(N)]
for i in range(N):
	L[i], R[i] = map(int, input().split())

# 階差 B[i] を計算する
for i in range(N):
	B[L[i]] += 1
	B[R[i]] -= 1

# 累積和 A[i] を計算する
A[0] = B[0]
for i in range(1, T):
	A[i] = A[i - 1] + B[i]

# 出力
for i in range(T):
	print(A[i])