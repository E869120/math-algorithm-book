l = 1.0
r = 2.0
repeats = 20

for i in range(1, repeats + 1):
	m = (l + r) / 2.0
	if m * m < 2.0:
		l = m
	else:
		r = m
	print("Step #%d: m = %.12f" % (i, m))