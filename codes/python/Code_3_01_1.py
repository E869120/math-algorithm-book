# 2 以上の整数 N に対し、N が素数であれば true、素数でなければ false を返す関数
def isprime(N):
	for i in range(2, N):
		if N % i == 0:
			return False # N が i で割り切れた場合、この時点で素数ではないと分かる
	return True

N = int(input())
if isprime(N):
	print("prime")
else:
	print("not prime")
