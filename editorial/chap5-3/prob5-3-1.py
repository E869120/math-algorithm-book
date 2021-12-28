# 入力
H, W = map(int, input().split())

# 場合分け
if H == 1 or W == 1:
	print(1)
else:
	print((H * W + 1) // 2)