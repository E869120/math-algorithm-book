def func(N):
	# func(N) → func(N-1) → ... → func(0) → func(-1) → func(-2) → ... と無限に呼び出されるので、プログラムが正常に動作しない
	return func(N - 1) * N

N = int(input())
print(func(N))
