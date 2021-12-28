# 入力
N = int(input())
A = [0.0 for i in range(N)]
B = [0.0 for i in range(N)]
C = [0.0 for i in range(N)]
for i in range(N):
	A[i], B[i], C[i] = map(float, input().split())

# 交点を全探索
Answer = 0.0
for i in range(0, N):
	for j in range(i + 1, N):
		# 交点を持たない場合
		if A[i] * B[j] == A[j] * B[i]:
			continue
		
		# i 番目の直線（条件式の境界）と j 番目の直線（条件式の境界）の交点を求める
		px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
		py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
		
		# 座標 (px, py) が N 個の条件すべてを満たすか調べる
		# C++ のコードにおける check 関数に相当
		ret = True
		for k in range(N):
			if A[k] * px + B[k] * py > C[k]:
				ret = False
		
		if ret == True:
			Answer = max(Answer, px + py)

# 出力
print("%.12f" % Answer)