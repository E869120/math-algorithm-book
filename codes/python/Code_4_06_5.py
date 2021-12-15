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

MOD = 1000000007

# 入力
X, Y = map(int, input().split())

# 二項係数の分子と分母を求める（手順 1.／手順 2.）
bunshi, bunbo = 1, 1
for i in range(1, X + Y + 1):
	bunshi = (bunshi * i) % MOD
for i in range(1, X + 1):
	bunbo = (bunbo * i) % MOD
for i in range(1, Y + 1):
	bunbo = (bunbo * i) % MOD

# 答えを求める（手順 3.）
print(division(bunshi, bunbo, MOD))
