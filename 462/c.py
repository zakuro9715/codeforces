N = int(input())
m = list(enumerate(sorted(list(map(int, input().split())))))
m[-1] = (m[-1][0] - 1, m[-1][1])

print(sum([(v[0] + 2) * v[1] for v in m]))
