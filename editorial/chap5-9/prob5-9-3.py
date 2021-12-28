# 入力
# A は (終了時刻, 開始時刻) になっていることに注意 [終了時刻の昇順にソートするため]
N = int(input())
A = []
for i in range(N):
	a, b = map(int, input().split())
	A.append([b, a])

# ソート
A.sort()

# 終了時刻が最も早いものを選び続ける
CurrentTime = 0
Answer = 0
for i in range(N):
	if CurrentTime <= A[i][1]:
		CurrentTime = A[i][0]
		Answer += 1

# 出力
print(Answer)