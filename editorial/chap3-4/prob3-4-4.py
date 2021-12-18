# 入力
N = int(input())

# 答えの計算
Answer = 0.0
for i in range(1, N+1):
	Answer += 1.0 * N / i

# 出力
print("%.12f" % Answer)