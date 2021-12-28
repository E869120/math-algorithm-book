# 入力
N = int(input())
X = [0 for i in range(N)]
Y = [0 for i in range(N)]
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 配列 X, Y をソートする
X.sort()
Y.sort()

# パーツ 1 の答え（x 座標の差の絶対値の総和）
Part1 = 0
for i in range(1, N + 1):
	Part1 += X[i - 1] * (-N + 2 * i - 1);

# パーツ 2 の答え（y 座標の差の絶対値の総和）
Part2 = 0
for i in range(1, N + 1):
	Part2 += Y[i - 1] * (-N + 2 * i - 1);

# 出力
print(Part1 + Part2)