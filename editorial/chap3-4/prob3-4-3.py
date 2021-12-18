# 入力
N = int(input())
A = [0 for i in range(N)]
B = [0 for i in range(N)]
for i in range(N):
	A[i],B[i] = map(int, input().split())

# 答えを求める
Answer = 0.0
for i in range(N):
	Answer += (1.0 / 3.0) * A[i] + (2.0 / 3.0) * B[i]

# 出力
print("%.12f" % Answer)