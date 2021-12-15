N, Q = map(int, input().split())
A = list(map(int, input().split()))
L = [ None ] * Q
R = [ None ] * Q
for j in range(Q):
	L[j], R[j] = map(int, input().split())

B = [ None ] * (N + 1)
B[0] = 0
for i in range(N):
	B[i + 1] = B[i] + A[i]

for j in range(Q):
	print(B[R[j]] - B[L[j] - 1])
