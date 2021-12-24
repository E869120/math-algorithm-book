import math

# 入力
A, B, H, M = map(float, input().split())

# 座標を求める
PI = 3.14159265358979
AngleH = 30.0 * H + 0.5 * M
AngleM = 6.0 * M
Hx = A * math.cos(AngleH * PI / 180.0)
Hy = A * math.sin(AngleH * PI / 180.0)
Mx = B * math.cos(AngleM * PI / 180.0)
My = B * math.sin(AngleM * PI / 180.0)

# 答えを出力
d = (((Hx - Mx) ** 2 + (Hy - My) ** 2) ** 0.5)
print("%.12f" % d)