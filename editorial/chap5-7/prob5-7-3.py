# 入力
N = int(input())
A = list(map(int, input().split()))

# 配列 A 全体をソートする
A.sort()

# 答えを求める
Answer = 0
for i in range(1, N + 1):
	Answer += A[i - 1] * (-N + 2 * i - 1)

# 出力
print(Answer)