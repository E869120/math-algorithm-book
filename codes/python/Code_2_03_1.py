cnt = 1000

def func1():
	return 2021

def func2(pos):
	global cnt # グローバル変数 cnt を関数の内部で使う
	cnt += 1
	return cnt + pos

print(func1()) # 「2021」と出力
print(func2(500)) # 「1501」と出力
print(func2(500)) # 「1502」と出力
