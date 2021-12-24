r = 2.0 # √2 を求めたいから
a = 2.0 # 初期値を適当に 2.0 にセットする
repeats = 5

for i in range(1, repeats + 1):
	# 点 (a, f(a)) の x 座標と y 座標を求める
	zahyou_x, zahyou_y = a, a * a * a
	
	# 接線の式 y = sessen_a * x + sessen_b を求める
	sessen_a = 3.0 * zahyou_x * zahyou_x
	sessen_b = zahyou_y - sessen_a * zahyou_x
	
	# 次の a の値 next_a を求める
	next_a = (r - sessen_b) / sessen_a
	print("Step #%d: a = %.12f -> %.12f" % (i, a, next_a))
	a = next_a