# 繰り返し二乗法（p は a**1, a**2, a**4, a**8, ... といった値をとる）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

MOD = 1000000007

a, b = map(int, input().split())
print(modpow(a, b, MOD))

# 補足
# 実は、Python では「a**b を m で割った余り」を繰り返し二乗法で求める関数 pow(a, b, m) が標準ライブラリとして使えます。
# Code_4_06_4_extra.py はこれを使ったプログラムです。こちらもぜひ見てください。
