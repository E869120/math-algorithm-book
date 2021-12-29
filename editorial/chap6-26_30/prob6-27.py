# 本プログラムを Python で提出すると、比較的処理が遅くなるため実行時間制限オーバー (TLE) となります。
# PyPy3 で提出すると、正解 (AC) することができます。

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
LIMIT = 100000

# 配列 fact の初期化（fact[i] は i の階乗を 1000000007 で割った余り）
fact = [ None ] * (LIMIT + 1)
fact[0] = 1
for i in range(1, LIMIT + 1):
	fact[i] = fact[i - 1] * i % MOD

# 入力 → 答えの出力
N = int(input())
for i in range(1, N + 1):
	answer = 0
	for j in range(1, (N - 1) // i + 2):
		answer += ncr(N - (i - 1) * (j - 1), j)
		answer %= MOD
	print(answer)