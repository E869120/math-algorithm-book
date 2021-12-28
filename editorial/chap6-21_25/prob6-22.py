# 本プログラムを Python で提出すると、比較的処理が遅くなるため実行時間制限オーバー (TLE) となります。
# PyPy3 で提出すると、正解 (AC) することができます。

# 入力
N = int(input())
T = list(map(int, input().split()))

# 配列の初期化
sumT = sum(T)
dp = [ [ False ] * (sumT + 1) for i in range(N + 1) ]
dp[0][0] = True

# 動的計画法
for i in range(1, N + 1):
	for j in range(sumT + 1):
		if j < T[i - 1]:
			if dp[i - 1][j] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False
		if j >= T[i - 1]:
			if dp[i - 1][j] == True or dp[i - 1][j - T[i - 1]] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False

# 答えを計算して出力
answer = 10 ** 10
for i in range(sumT + 1):
	if dp[N][i] == True:
		cooking_time = max(i, sumT - i)
		answer = min(answer, cooking_time)
print(answer)