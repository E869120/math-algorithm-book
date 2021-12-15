import math

a, b, c = map(int, input().split())

if math.sqrt(a) + math.sqrt(b) < math.sqrt(c):
	print("Yes")
else:
	print("No")
