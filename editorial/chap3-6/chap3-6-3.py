def MergeSort(A):
	# 長さが 1 の場合、すでにソートされているので何もしない
	if len(A) == 1:
		return A
	
	# 2 つに分割した後、小さい配列をソート
	m = len(A) // 2
	A_Dash = MergeSort(A[0:m])
	B_Dash = MergeSort(A[m:len(A)])
	
	# この時点で以下の 2 つの配列がソートされている：
	# 列 A' に相当するもの [A_Dash[0], A_Dash[1], ..., A_Dash[m-1]]
	# 列 B' に相当するもの [B_Dash[0], B_Dash[1], ..., B_Dash[len(A)-m-1]]
	# 以下が Merge 操作となります。
	c1 = 0
	c2 = 0
	C = []
	while (c1 < len(A_Dash) or c2 < len(B_Dash)):
		if c1 == len(A_Dash):
			# 列 A' が空の場合
			C.append(B_Dash[c2])
			c2 += 1
		elif c2 == len(B_Dash):
			# 列 B' が空の場合
			C.append(A_Dash[c1])
			c1 += 1
		else:
			# そのいずれでもない場合
			if A_Dash[c1] <= B_Dash[c2]:
				C.append(A_Dash[c1])
				c1 += 1
			else:
				C.append(B_Dash[c2])
				c2 += 1
	
	# 列 A', 列 B' を合併した配列 C を返す
	return C

# 以下、メイン部分
N = int(input())
A = list(map(int, input().split()))

# マージソート → 答えの出力
Answer = MergeSort(A)
print(*Answer)