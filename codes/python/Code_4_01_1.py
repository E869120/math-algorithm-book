import math

# 入力
ax, ay, bx, by, cx, cy = map(int, input().split())

# ベクトル BA, BC, CA, CB の成分表示を求める
BAx, BAy = ax - bx, ay - by
BCx, BCy = cx - bx, cy - by
CAx, CAy = ax - cx, ay - cy
CBx, CBy = bx - cx, by - cy

# どのパターンに当てはまるか判定する
pattern = 2
if BAx * BCx + BAy * BCy < 0:
	pattern = 1
if CAx * CBx + CAy * CBy < 0:
	pattern = 3

# 点と直線の距離を求める
if pattern == 1:
	answer = math.sqrt(BAx ** 2 + BAy ** 2)
if pattern == 3:
	answer = math.sqrt(CAx ** 2 + CAy ** 2)
if pattern == 2:
	S = abs(BAx * CAy - BAy * CAx)
	BCLength = math.sqrt(BCx ** 2 + BCy ** 2)
	answer = S / BCLength

# 答えの出力
print("%.12f" % answer)
