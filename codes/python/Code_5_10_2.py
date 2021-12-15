a, b, c = map(int, input().split())
if c - a - b < 0:
	print("No")
elif 4 * a * b < (c - a - b) * (c - a - b):
	print("Yes")
else:
	print("No")
