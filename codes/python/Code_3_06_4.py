def GCD(A, B):
	if B == 0:
		return A  # ベースケース
	return GCD(B, A % B)

A, B = map(int, input().split())
print(GCD(A, B))
