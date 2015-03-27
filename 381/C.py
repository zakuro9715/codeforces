m = input()
sq = []
for i in range(m):
  q = map(int, raw_input().split())
  if q[0] == 1:
    sq.append(q[1])
  else:
    sq += sq[:q[1]] * q[2]
n = input()
r = map(int, raw_input().split())
print sq
for v in r:
  print sq[v - 1],
print
