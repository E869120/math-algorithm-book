from copy import deepcopy

MOD = 1000000007

# 2×2 行列 A, B の積を返す関数
def multiply(A, B):
	global MOD
	C = [ [ 0, 0 ], [ 0, 0 ] ]
	for i in range(2):
		for j in range(2):
			for k in range(2):
				C[i][j] += A[i][k] * B[k][j]
				C[i][j] %= MOD
	return C

# A の n 乗を返す関数
def power(A, n):
	P = deepcopy(A)
	Q = [ [ 0, 0 ], [ 0, 0 ] ]
	flag = False
	for i in range(60):
		if (n & (1 << i)) != 0:
			if flag == False:
				Q = deepcopy(P)
				flag = True
			else:
				Q = deepcopy(multiply(Q, P))
		P = deepcopy(multiply(P, P))
	return Q

# 入力 → 累乗の計算（N が 2 以上でなければ正しく動作しないので注意）
N = int(input())
A = [ [ 2, 1 ], [ 1, 0 ] ]
B = power(A, N - 1)

# 答えの計算 → 出力
answer = (B[1][0] + B[1][1]) % MOD
print(answer)