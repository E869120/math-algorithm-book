MOD = 1000000007

a, b = map(int, input().split())

answer = 1  # a の 0 乗は 1 なので、answer = 1 に初期化しておく
for i in range(b):
	answer = (answer * a) % MOD

print(answer)
