N = int(input()) # 入力部分
answer = ""

while N >= 1:
	# N % 2 は N を 2 で割った余り（例：N = 13 の場合 1）
	# N // 2 は N を 2 で割った値の整数部分（例：N = 13 の場合 6）
	if N % 2 == 0:
		answer = "0" + answer
	if N % 2 == 1:
		answer = "1" + answer
	N = N // 2

print(answer) # 出力部分
