# ����
N = int(input())
A = list(map(int, input().split()))

# �����̌v�Z
Answer = 0
for i in range(N):
    Answer += A[i]

# �o��
print(Answer % 100)