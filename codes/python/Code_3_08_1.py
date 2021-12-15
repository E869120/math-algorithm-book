# 入力
N, X = map(int, input().split())
A = list(map(int, input().split()))

# 配列のソート
A.sort()

# 二分探索
answer = "No"
left, right = 0, N - 1
while left <= right:
	mid = (left + right) // 2
	if A[mid] == X:
		answer = "Yes"
		break
	if A[mid] > X:
		# 探索範囲を前半部分に絞る
		right = mid - 1
	if A[mid] < X:
		# 探索範囲を後半部分に絞る
		left = mid + 1

# 答えの出力
print(answer)
