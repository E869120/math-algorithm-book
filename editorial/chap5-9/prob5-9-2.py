# 入力
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 配列 A, B をソートする
A.sort()
B.sort()

# 答えを求める
Answer = 0
for i in range(N):
	Answer += abs(A[i] - B[i])

# 出力
print(Answer)