# この解法の計算量は O(N) です（5.7 節のテクニックを利用）
# PyPy3 (7.3.0) だけでなく Python (3.8.2) でも AC します

N = int(input())
Answer = 0

for i in range(1, N+1):
	d = (N // i)
	Answer += i * (d * (d + 1) // 2)

print(Answer)