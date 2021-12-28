import math

r = 2.0 # y = e^x と y = 2 の交点を求めたいから
a = 1.0 # 初期値を適当に 1.0 にセットする
repeats = 5

for i in range(1, repeats + 1):
	# 点 (a, f(a)) の x 座標と y 座標を求める
	zahyou_x, zahyou_y = a, math.exp(a)
	
	# 接線の式 y = sessen_a * x + sessen_b を求める
	sessen_a = zahyou_y
	sessen_b = zahyou_y - sessen_a * zahyou_x
	
	# 次の a の値 next_a を求める
	next_a = (r - sessen_b) / sessen_a
	print("Step #%d: a = %.15f -> %.15f" % (i, a, next_a))
	a = next_a