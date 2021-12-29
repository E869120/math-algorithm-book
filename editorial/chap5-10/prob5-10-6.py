# 整数 m の各桁の積を返す関数
def product(m):
	if m == 0:
		return 0
	ans = 1
	while m >= 1:
		ans *= (m % 10)
		m //= 10
	return ans

# 各桁の積の候補の集合を返す関数
def func(digit, m):
	if digit == 11:
		return {product(m)}
	
	# 次の桁を探索
	# min_value は cur の最後の桁（単調増加にするためには次の桁がそれ以上でなければならない）
	min_value = m % 10
	ret = set()
	for i in range(min_value, 10):
		r = func(digit + 1, m * 10 + i)
		for j in r:
			ret.add(j)
	return ret

# 入力
N, B = map(int, input().split())

# 各桁の積の候補を列挙
fm_cand = func(0, 0)

# m - f(m) = B になるかどうかチェック
Answer = 0
for fm in fm_cand:
	m = fm + B # 各桁の積から導かれる m の値
	prod_m = product(m) # 本来の f(m) の値
	if m - prod_m == B and m <= N:
		Answer += 1

# 出力
print(Answer)