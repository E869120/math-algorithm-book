# 正の整数 A と B の最大公約数を返す関数
# GCD は Greatest Common Divisor（最大公約数）の略
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B の場合、大きい方 B を書き換える
		else:
			A = A % B  # A >= B の場合、大きい方 A を書き換える
	if A >= 1:
		return A
	return B

A, B = map(int, input().split())
print(GCD(A, B))
