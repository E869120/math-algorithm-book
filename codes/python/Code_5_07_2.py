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

# ncr は n! を r! × (n-r)! で割った値
def ncr(n, r):
	global fact, MOD
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD)

MOD = 1000000007
LIMIT = 200000

# 配列 fact の初期化（fact[i] は i の階乗を 1000000007 で割った余り）
fact = [ None ] * (LIMIT + 1)
fact[0] = 1
for i in range(1, LIMIT + 1):
	fact[i] = fact[i - 1] * i % MOD

# 入力
N = int(input())
A = list(map(int, input().split()))

# 答えを求める
answer = 0
for i in range(N):
	answer += A[i] * ncr(N - 1, i)
	answer %= MOD

# 答えの出力
print(answer)
