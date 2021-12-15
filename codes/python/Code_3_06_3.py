def func(N):
	if N == 1:
		return 1  # このような場合分けすべきケースを「ベースケース」といいます
	return func(N - 1) * N

N = int(input())
print(func(N))

# Python では、呼び出せる再帰関数の深さに上限が設定されており、デフォルトでは 1000 などの深さに設定されています。
# この上限は、sys.getrecursionlimit() を呼び出すことで取得できます。
# 一方、sys.setrecursionlimit(depth) を呼び出すことで、再帰呼び出しの深さ depth の上限を変えることができます。
# （これらの機能を使うためには、最初に import sys と書く必要があります）
