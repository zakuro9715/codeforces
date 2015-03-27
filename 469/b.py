p, q, l, r = map(int, input().split())

pv = [0] * 3000
qv = [0] * 3000

for i in range(p):
    a, b = map(int, input().split())
    pv[a] = 1
    pv[b + 1] = -1

for i in range(q):
    a, b = map(int, input().split())
    qv[1500 + a] = 1
    qv[1500 + b + 1] = -1

n = 0
for o in range(l, r + 1):
    t, pn, qn = 0, 0, 0
    for i in range(0, 1500 - o):
        pn += pv[i]
        qn += qv[1500 + i - o]
        if pn and qn:
            t += 1
    if t:
        n += 1
print(n)
