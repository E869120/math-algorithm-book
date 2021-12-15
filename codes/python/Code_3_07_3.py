# 注意
# Python は配列のランダムアクセスに時間がかかるため、N = 100, W = 100000 では実行に 5 秒程度かかり、TLE（実行時間制限オーバー）になります。
# 一方、同じプログラムを PyPy3 で提出すると、実行に 0.5 秒程度しかかからず、AC（正解）することができます。

# 入力
N, W = map(int, input().split())
w = [ None ] * N
v = [ None ] * N
for i in range(N):
	w[i], v[i] = i ** 2, i ** 3
	# w[i], v[i] = map(int, input().split())

# 配列の初期化
INF = 10 ** 18
dp = [ [ None ] * (W + 1) for i in range(N + 1) ]
dp[0][0] = 0
for i in range(1, W + 1):
	dp[0][i] = -INF

# 動的計画法
for i in range(1, N + 1):
	for j in range(0, W + 1):
		if j < w[i - 1]:
			# j < w[i-1] のとき、方法 A だけしか選べない
			dp[i][j] = dp[i - 1][j]
		else:
			# j >= w[i-1] のとき、方法 A・方法 B どちらも選べる
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1])

# 答えを計算して出力
answer = max(dp[N])
print(answer)
