# 入力
N = int(input())
A = list(map(int, input().split()))

# 2^i を求める
mod = 1000000007
power = [0 for i in range(N)]
power[0] = 1
for i in range(1, N):
	power[i] = (2 * power[i - 1]) % mod

# 答えを求める
Answer = 0
for i in range(N):
	Answer += power[i] * A[i]
	Answer %= mod

# 出力
print(Answer)