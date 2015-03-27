m = [False] * int(input())
X = map(int , input().split())
Y = map(int , input().split())

for x in X:
    m[x - 1] = True
for y in Y:
    m[y - 1] = True

print('I become the guy.' if all(m) else 'Oh, my keyboard!')
