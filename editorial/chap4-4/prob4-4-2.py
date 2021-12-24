N = 1000
Answer = 0.0

for i in range(N):
	x = 1.0 * (2 * i + 1) / (2 * N)
	value = 2.0 ** (x * x)
	Answer += value

print("%.12f" % (Answer / N))