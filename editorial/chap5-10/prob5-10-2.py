# 入力
N = int(input())

# 答えを求める
mod = 1000000007
val = N * (N + 1) // 2
print(val * val % mod)