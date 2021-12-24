# 入力
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = [0 for i in range(M)]
for i in range(M):
	B[i] = int(input())

# 累積和をとる
S = [0 for i in range(N)]
for i in range(1, N):
	S[i] = S[i - 1] + A[i - 1]

# 答えを求める
# B[i] - 1 などになっているのは、配列の index が 0 始まりだから
Answer = 0
for i in range(M-1):
	if B[i] < B[i + 1]:
		Answer += S[B[i + 1] - 1] - S[B[i] - 1]
	else:
		Answer += S[B[i] - 1] - S[B[i + 1] - 1]

# 出力
print(Answer)