N, X, Y = map(int, input().split())

if Y > N ** 4:
	print("No")
else:
	d = []
	for i in range(1, N + 1):
		if Y % i == 0:
			d.append(i)
	divcnt = len(d)
	flag = False
	for i in range(0, divcnt):
		for j in range(i, divcnt):
			for k in range(j, divcnt):
				for l in range(k, divcnt):
					if d[i] + d[j] + d[k] + d[l] == X and d[i] * d[j] * d[k] * d[l] == Y:
						flag = True
	if flag == True:
		print("Yes")
	else:
		print("No")

# 実は、このプログラムの計算量は O(N) です。
# この理由をぜひ考えてみましょう。
