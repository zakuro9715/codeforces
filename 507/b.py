eps = 0.00000001
r, x1, y1, x2, y2 = map(int, input().split())

d = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5)
r *= 2
print(int(d // r) + (1 if abs(d // r - d / r) > eps else 0))
