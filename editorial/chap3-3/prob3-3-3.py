# 入力
n,r = map(int, input().split())

# 階乗の計算
fact_n = 1
for i in range(1, n+1):
	fact_n *= i

fact_r = 1
for i in range(1, r+1):
	fact_r *= i

fact_nr = 1
for i in range(1, n-r+1):
	fact_nr *= i

# 出力
print(int(fact_n / (fact_r * fact_nr)))