N = int(input())
A = list(map(int, input().split()))
Answer = 0

for item in A:
    Answer += item

print(Answer)