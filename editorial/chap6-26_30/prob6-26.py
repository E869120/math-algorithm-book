# Python では、行列の T 乗を求める関数が numpy のライブラリにあります。
# これを使うと、次のように非常に短いプログラムでこの問題が解けます。
# もちろん、繰り返し二乗法を使って解くこともできます。これについては、コード 4.7.1（Python 版）などを参照してください。

import numpy as np

Q = int(input())
for i in range(Q):
	S = input().split()
	X, Y, Z, T = float(S[0]), float(S[1]), float(S[2]), int(S[3])
	A = np.array([[ 1 - X, Y, 0 ], [ 0, 1 - Y, Z ], [ X, 0, 1 - Z ]])
	answer = np.linalg.matrix_power(A, T)
	print("%.15f %.15f %.15f" % (sum(answer[0]), sum(answer[1]), sum(answer[2])))