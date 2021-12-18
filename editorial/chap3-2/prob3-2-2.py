# 正の整数 A と B の最大公約数を返す関数
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B の場合、大きい方 B を書き換える
		else:
			A = A % B  # A >= B の場合、大きい方 A を書き換える
	if A >= 1:
		return A
	return B

# 入力
N = int(input())
A = list(map(int, input().split()))

# 答えを求める
R = GCD(A[0], A[1])
for i in range(2, N):
	R = GCD(R, A[i])

# 出力
print(R)