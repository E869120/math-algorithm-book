def solve(l, r, A):
	if r - l == 1:
		return A[l]
	m = (l + r) // 2  # 区間 [l, r) の中央で分割する
	s1 = solve(l, m, A)  # s1 は A[l] + ... + A[m-1] の合計値となる
	s2 = solve(m, r, A)  # s2 は A[m] + ... + A[r-1] の合計値となる
	return s1 + s2

# 入力
N = int(input())
A = list(map(int, input().split()))

# 再帰呼び出し → 答えの出力
answer = solve(0, N, A)
print(answer)
