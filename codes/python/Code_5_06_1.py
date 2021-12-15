# 小問題 t を解く関数
def shou_mondai(A, B, t):
	cl = (A + t - 1) // t  # A÷t の小数点以下切り上げ
	cr = B // t  # B÷t の小数点以下切り捨て
	if cr - cl >= 1:
		return True
	else:
		return False

A, B = map(int, input().split())
for i in range(1, B + 1):
	if shou_mondai(A, B, i) == True:
		answer = i
print(answer)
