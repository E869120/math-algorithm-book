# 入力
L, R = map(int, input().split())

# 配列の初期化・L=1 のときの場合分け
isprime = [ True ] * (R - L + 1)
if L == 1:
	isprime[0] = False

# ふるい
LIMIT = int(R ** 0.5)
for i in range(2, LIMIT + 1):
	min_value = ((L + i - 1) // i) * i
	for j in range(min_value, R + 1, i):
		if j == i:
			continue
		isprime[j - L] = False

# 個数を数えて出力
answer = 0
for i in range(R - L + 1):
	if isprime[i] == True:
		answer += 1
print(answer)