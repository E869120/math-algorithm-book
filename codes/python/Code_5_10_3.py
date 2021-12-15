# 入力
N, X, Y = map(int, input().split())

# 4 つの整数 (a, b, c, d) の全探索
flag = False
for a in range(1, N + 1):
	for b in range(a, N + 1):
		for c in range(b, N + 1):
			for d in range(c, N + 1):
				if a + b + c + d == X and a * b * c * d == Y:
					flag = True  # 答えが見つかったら flag を true にする

# 答えの出力
if flag == True:
	print("Yes")
else:
	print("No")

# p.256 注 5.10.2 に書かれてあるように、Python は実行速度が遅いので、最大ケースでは実行に数十秒かかります。
# しかし、同じプログラムを PyPy3 で実行すると、最大ケースでも 1 秒ほどで答えを求めることができます。
# より良い計算量のプログラムについては、Code_5_10_3_extra.py を見てください。
