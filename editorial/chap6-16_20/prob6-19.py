# 入力（配列 B の添え字が 0 始まりなことに注意してください）
N = int(input())
B = list(map(int, input().split()))

# 数列 A の要素の合計を求める
answer = B[0] + B[N - 2]
for i in range(1, N - 1):
	answer += min(B[i - 1], B[i])

# 答えの出力
print(answer)