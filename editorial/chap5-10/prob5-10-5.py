import sys

# 入力
a, b, c = map(int, input().split())

# c = 1 のときの場合分け
if c == 1:
	print("No")
	sys.exit()

# 右辺の計算（c の b 乗）
v = 1
for i in range(b):
	v *= c
	if a < v:
		print("Yes")
		sys.exit()

# 出力（No の場合）
print("No")