# 入力
N = int(input())
A = list(map(int, input().split()))

# 答えの計算
Answer = 0
for i in range(N):
    Answer += A[i]

# 出力
print(Answer % 100)
