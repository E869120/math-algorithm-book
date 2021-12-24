# 繰り返し二乗法（p は a**1, a**2, a**4, a**8, ... といった値をとる）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(60):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) は a÷b mod m を返す関数
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# 入力
MOD = 1000000007
N = int(input())

# 答えの計算
V = modpow(4, N + 1, MOD) - 1
Answer = division(V, 3, MOD)

# 出力
print(Answer)