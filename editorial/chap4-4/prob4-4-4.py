cnt = 0
LIMIT = 23 # これを 30 にすれば答えが求められる
Current = 0

# 1 つずつ足していく
while Current < LIMIT:
	cnt += 1
	Current += 1.0 / cnt

# 出力
print(cnt)