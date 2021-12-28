# 最大公約数を返す関数
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B の場合、大きい方 B を書き換える
		else:
			A = A % B  # A >= B の場合、大きい方 A を書き換える
	if A >= 1:
		return A
	return B

# 最小公倍数を返す関数
def LCM(A, B):
	return int(A / GCD(A, B)) * B

# 入力
N, K = map(int, input().split())
V = list(map(int, input().split()))

# ビット全探索
Answer = 0
for i in range(1, 1 << K):
	cnt = 0
	lcm = 1
	for j in range(K):
		if (i & (1 << j)) != 0:
			cnt += 1
			lcm = LCM(lcm, V[j])
			
	# num は N 以下の中で選ばれたすべての倍数であるものの個数
	num = N // lcm
	if cnt % 2 == 1:
		Answer += num
	else:
		Answer -= num

# 出力
print(Answer)