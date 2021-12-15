def check_numpoints(N, X, Y, lx, rx, ly, ry):
	cnt = 0
	for i in range(N):
		# 点 (X[i], Y[i]) が長方形に含まれているかどうかを判定する
		if lx <= X[i] and X[i] <= rx and ly <= Y[i] and Y[i] <= ry:
			cnt += 1
	return cnt

# 入力
N, K = map(int, input().split())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 左端 x、右端 x、下端 y、上端 y を全探索（それぞれの番号が i, j, k, l）
answer = 10 ** 19  # あり得ない値に設定
for i in range(N):
	for j in range(N):
		for k in range(N):
			for l in range(N):
				# cl <= x <= cr, dl <= y <= dr の長方形
				# 長方形を作るためには、cl < cr, dl < dr である必要がある
				cl, cr, dl, dr = X[i], X[j], Y[k], Y[l]
				if cl < cr and dl < dr:
					if check_numpoints(N, X, Y, cl, cr, dl, dr) >= K:
						area = (cr - cl) * (dr - dl)
						answer = min(answer, area)

# 答えの出力
print(answer)

# この問題は実行時間制限が厳しく、コード 5.5.2 の書き方をすると PyPy3 でも最大 2.5 秒程度の実行がかかり、AtCoder に提出すると TLE となります。
# しかし、「cl < cr」と「dl < dr」を満たすものに限定して探索すると、探索する長方形の数がおよそ 1/4 になります。
# これを利用したプログラムを PyPy3 で提出すると、1 秒以内に実行が終わり、正解 (AC) が得られます。
