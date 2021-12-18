import random

N = 1000000 # N は試行回数（適宜変更する）
M = 0
for i in range(N):
	px = 6.0 * random.random()
	py = 9.0 * random.random()
	
	# 点 (3, 3) との距離。この値が 3 以下であれば半径 3 の円に含まれる。
	dist_33 = ((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0)) ** 0.5
	
	# 点 (3, 7) との距離。この値が 2 以下であれば半径 2 の円に含まれる。
	dist_37 = ((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0)) ** 0.5
	
	# 判定
	if (dist_33 <= 3.0 or dist_37 <= 2.0):
		M += 1

print(M)