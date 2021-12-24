# 重要な注意
# Python は遅いので、このプログラムを提出しても、実行時間制限超過（TLE）となります。
# このため、全く同じコードを「PyPy3 (7.3.0)」で提出してください。おそらく AC します。
# 計算量の速い解法を知りたい人は「prob4-4-3_fast.py」をご覧ください。

# 入力
N = int(input())
F = [0 for i in range(N + 1)]

# F[1], F[2], ..., F[N] を計算する
for i in range(1, N + 1):
	# F[i], F[2i], F[3i], ... に 1 を加算
	for j in range(1, (N // i) + 1):
		F[j * i] += 1

# 答えを求める
Answer = 0
for i in range(1, N + 1):
	Answer += i * F[i]

# 出力
print(Answer)