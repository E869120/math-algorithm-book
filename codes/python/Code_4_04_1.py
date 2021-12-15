# 入力 → 配列 prime の初期化
N = int(input())
prime = [ True ] * (N + 1)

# エラトステネスのふるい
LIMIT = int(N ** 0.5)
for i in range(2, LIMIT + 1):
	if prime[i] == True:
		# x = 2i, 3i, 4i, ... と、N 以下の間ループし続ける
		for j in range(2 * i, N + 1, i):
			prime[j] = False

# N 以下の素数を小さい順に出力
for i in range(2, N + 1):
	if prime[i] == True:
		print(i)
