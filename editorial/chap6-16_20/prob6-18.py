# ユークリッドの互除法を使って最大公約数を求めます（別の方法として、標準ライブラリ math.gcd(A, B) を使う手もあります）
def GCD(A, B):
	if B == 0:
		return A
	return GCD(B, A % B)

# 入力
A, B = map(int, input().split())

# 最小公倍数を求める（注：Python ではオーバーフローを気にする必要はありません）
L = A * B // GCD(A, B)
if L > 10 ** 18:
	print("Large")
else:
	print(L)