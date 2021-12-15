# 入力
N = int(input())
L = [ None ] * N
R = [ None ] * N
for i in range(N):
	L[i], R[i] = map(int, input().split())

# 映画の選び方のシミュレーション
# 見れる映画の終了時刻の最小値 min_endtime は、最初 1000000 (INF で設定）のようなあり得ない値にセットする
INF = 1000000
current_time = 0  # current_time は現在時刻（直前に見た映画の終了時刻）
answer = 0
while True:
	min_endtime = INF
	for i in range(N):
		if L[i] >= current_time:
			min_endtime = min(min_endtime, R[i])
	if min_endtime == INF:
		break
	current_time = min_endtime
	answer += 1

# 答えの出力
print(answer)
