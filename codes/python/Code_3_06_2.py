# 入力
N = int(input())
A = list(map(int, input().split()))

# 選択ソート
for i in range(N - 1):
	min_position = i
	min_value = A[i]
	for j in range(i + 1, N):
		if A[j] < min_value:
			min_position = j  # min_position は最小値のインデックス（0 ～ N-1）
			min_value = A[j]  # min_value は現時点での最小値
	# A[i] と A[min_position] を交換
	A[i], A[min_position] = A[min_position], A[i]

# 出力
for i in range(N):
	print(A[i])
