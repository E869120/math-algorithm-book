# 注意
# Python で提出すると、N = 100 では実行に 10 秒程度かかり、TLE（実行時間制限オーバー）になります。
# 一方、同じプログラムを PyPy3 で提出すると、実行に 0.5 秒程度しかかからず、AC（正解）することができます。

# 入力
N = int(input())
A = list(map(int, input().split()))

# 5 つのカードの番号 (i, j, k, l, m) を全探索
answer = 0
for i in range(0, N):
	for j in range(i + 1, N):
		for k in range(j + 1, N):
			for l in range(k + 1, N):
				for m in range(l + 1, N):
					if A[i] + A[j] + A[k] + A[l] + A[m] == 1000:
						answer += 1

# 出力
print(answer)
