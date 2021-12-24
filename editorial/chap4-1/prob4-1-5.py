# ベクトル (ax, ay) と (bx, by) の内積の大きさ
def cross(ax, ay, bx, by):
	return ax * by - ay * bx

# 入力
X1, Y1 = map(int, input().split())
X2, Y2 = map(int, input().split())
X3, Y3 = map(int, input().split())
X4, Y4 = map(int, input().split())

# cross の値を計算
ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);

# すべて一直線上に並んでいる場合（コーナーケース）
if ans1 == 0 and ans2 == 0 and ans3 == 0 and ans4 == 0:
	# A, B, C, D を数値（正確には pair 型）とみなす
	# 適切に swap することで A<B, C<D を仮定できる
	# そうすると、区間が重なるかの判定（節末問題 2.5.6）に帰着できる
	A = (X1, Y1) # 点 A の座標
	B = (X2, Y2) # 点 B の座標
	C = (X3, Y3) # 点 C の座標
	D = (X4, Y4) # 点 D の座標
	if A > B:
		tmp = B
		B = A
		A = tmp
	if C > D:
		tmp = D
		D = C
		C = tmp
	if max(A, C) <= min(B, D):
		print("Yes")
	else:
		print("No")

# そうでない普通の場合
else:
	IsAB = False # IsAB: 線分 AB が点 C, D を分けるか？
	IsCD = False # IsCD: 線分 CD が点 A, B を分けるか？
	if ans1 >= 0 and ans2 <= 0:
		IsAB = True
	if ans1 <= 0 and ans2 >= 0:
		IsAB = True
	if ans3 >= 0 and ans4 <= 0:
		IsCD = True
	if ans3 <= 0 and ans4 >= 0:
		IsCD = True
	
	# 答えの出力
	if IsAB == True and IsCD == True:
		print("Yes")
	else:
		print("No")