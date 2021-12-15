# 入力
N = int(input())
B = list(map(int, input().split()))
R = list(map(int, input().split()))

# 答えの計算（Python 3 では B[i] / N, R[i] / N は小数まで計算されることに注意）
blue = 0.0
red = 0.0
for i in range(N):
	blue += B[i] / N
	red += R[i] / N

# 出力
print("%.12f" % (blue + red))
