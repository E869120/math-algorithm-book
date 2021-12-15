# 正の整数 A と B の最大公約数を返す関数
# GCD は Greatest Common Divisor（最大公約数）の略
def GCD(A, B):
	answer = 0
	for i in range(1, min(A, B) + 1):
		if A % i == 0 and B % i == 0:
			answer = i
	return answer

A, B = map(int, input().split())
print(GCD(A, B))
