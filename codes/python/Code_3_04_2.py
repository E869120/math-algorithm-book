# 入力
N = int(input())
P = [ None ] * N
Q = [ None ] * N
for i in range(N):
	P[i], Q[i] = map(int, input().split())

# 答えの計算（Python 3 では Q[i] / P[i] は小数まで計算されることに注意）
answer = 0
for i in range(N):
	answer += Q[i] / P[i]

# 出力
print("%.12f" % answer)
