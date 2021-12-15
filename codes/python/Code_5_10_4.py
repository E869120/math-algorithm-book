# 入力
N = int(input())
S = input()

# '(' の数 - ')' の数を depth とする
# 途中で depth が負になったら、この時点で No
depth = 0
flag = True
for i in range(N):
	if S[i] == '(':
		depth += 1
	if S[i] == ')':
		depth -= 1
	if depth < 0:
		flag = False

# 最後、depth = 0 ['(' と ')' の数が同じ] であるかも追加で判定する
if flag == True and depth == 0:
	print("Yes")
else:
	print("No")
