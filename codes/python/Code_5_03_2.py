# 入力 → 数列の要素の総和 S を求める
N, K = map(int, input().split())
A = list(map(int, input().split()))
S = sum(A)

# 答えの出力
if S % 2 != K % 2:
	print("No")
elif S > K:
	print("No")
else:
	print("Yes")
