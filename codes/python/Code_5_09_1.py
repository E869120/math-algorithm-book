N = int(input())

answer = 0

# 10000 円以上の間、10000 円札を使い続ける
while N >= 10000:
	N -= 10000
	answer += 1

# 5000 円以上の間、5000 円札を使い続ける
while N >= 5000:
	N -= 5000
	answer += 1

# 残った金額を 1000 円札で支払う
while N >= 1:
	N -= 1000
	answer += 1

print(answer)
