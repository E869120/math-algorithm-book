import math # math.sqrt 関数を使うためには、math モジュールを import する必要がある

# 四則演算
print(869 + 120) # 989 と出力
print(869 - 120) # 749 と出力
print(869 * 120) # 104280 と出力
print(869 // 120) # 7 と出力（Python 3 では、"//" は割り算の商を求める一方、"/" は小数部分も求めることに注意）

# 剰余 (mod)
print(8 % 5) # 3 と出力
print(869 % 120) # 29 と出力

# 絶対値 (abs)
print(abs(-45)) # 45 と出力
print(abs(15)) # 15 と出力

# 累乗
print(10 ** 2) # 100 と出力
print(3 ** 4) # 81 と出力

# 平方根 (sqrt)
print("%.5f" % math.sqrt(4.0)) # 2.00000 と出力
print("%.5f" % math.sqrt(2.0)) # 1.41421 と出力
