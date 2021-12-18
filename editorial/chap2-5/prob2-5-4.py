def isprime(N):
	for i in range(2, N):
		if N % i == 0:
			return False
	return True

N = int(input())
A = []
for i in range(2,N+1):
	if isprime(i) == True:
		A.append(i)

print(*A)