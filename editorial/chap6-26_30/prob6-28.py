# 本プログラムを Python で提出すると、比較的処理が遅くなるため実行時間制限オーバー (TLE) となります。
# PyPy3 で提出すると、正解 (AC) することができます。

# リュカの定理で ncr mod 3 を計算
def ncr(n, r):
	if n < 3 and r < 3:
		A = [
			[ 1, 0, 0 ],
			[ 1, 1, 0 ],
			[ 1, 2, 1 ]
		]
		return A[n][r]
	return ncr(n // 3, r // 3) * ncr(n % 3, r % 3) % 3

# 入力
N = int(input())
C = input()

# 答えを求める
answer = 0
for i in range(N):
	code = "BWR".find(C[i])
	answer += code * ncr(N - 1, i)
	answer %= 3

# 答えを (-1)^(N-1) で掛ける
if N % 2 == 0:
	answer = (3 - answer) % 3

# 答えを出力（"BWR" の answer 文字目）
print("BWR"[answer])