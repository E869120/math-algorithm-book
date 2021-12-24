# 繰り返し二乗法（p は a**1, a**2, a**4, a**8, ... といった値をとる）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) は a÷b mod m を返す関数
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# 入力
X, Y = map(int, input().split())
mod = 1000000007

# 場合分け（a, b が負になってしまう場合）
if (2 * Y - X) < 0 or (2 * X - Y) < 0:
	print(0)

# 場合分け（a, b が整数にならない場合）
elif (2 * Y - X) % 3 != 0 or (2 * X - Y) % 3 != 0:
	print(0)

# 答えがゼロではないケースの場合
else:
	bunshi = 1
	bunbo = 1
	a = (2 * Y - X) // 3
	b = (2 * X - Y) // 3
	
	# 二項係数の分母と分子を求める（手順 1. / 手順 2.）
	for i in range(1, a + b + 1):
		bunshi *= i
		bunshi %= mod
	for i in range(1, a + 1):
		bunbo *= i
		bunbo %= mod
	for i in range(1, b + 1):
		bunbo *= i
		bunbo %= mod
	
	# 答えを求める（手順 3.）
	print(division(bunshi, bunbo, mod))