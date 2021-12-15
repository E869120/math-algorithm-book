# 2 以上の整数 N に対し、N が素数であれば true、素数でなければ false を返す関数
def isprime(N):
	LIMIT = int(N ** 0.5)
	for i in range(2, LIMIT + 1):
		if N % i == 0:
			return False
	return True

N = int(input())
if isprime(N):
	print("prime")
else:
	print("not prime")
