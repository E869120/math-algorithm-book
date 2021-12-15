import random

N = 10000 # N は試行回数（適宜変更する）
M = 0
for i in range(N):
	px = random.random() # 0 以上 1 未満の乱数を生成（C++ のコード 3.5.1 では 0 以上 1 以下の乱数を生成しているが、ほとんど同じ）
	py = random.random() # 0 以上 1 未満の乱数を生成（C++ のコード 3.5.1 では 0 以上 1 以下の乱数を生成しているが、ほとんど同じ）
	# 原点からの距離は sqrt(px * px + py * py)
	# これが 1 以下であれば良いので、条件は「px * px + py * py <= 1」（「sqrt(px * px + py * py) <= 1」と同値）
	if px * px + py * py <= 1.0:
		M += 1

print("%.12f" % (4 * M / N))
