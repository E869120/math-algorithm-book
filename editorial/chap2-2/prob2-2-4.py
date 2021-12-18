# “ü—Í
N = int(input())
A = list(map(int, input().split()))

# “š‚¦‚ÌŒvZ
Answer = 0
for i in range(N):
    Answer += A[i]

# o—Í
print(Answer % 100)