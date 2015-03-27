s, t = input(), input()
m = [[0] * 100, [0] * 100]
for c in s:
    m[0][ord(c) - ord('a')] += 1
for c in t:
    m[1][ord(c) - ord('a')] += 1
for i in range(100):
    if m[0][i] < m[1][i]:
        print('need tree')
        exit()
if len(s) == len(t):
    print('array')
elif t in s:
    print('automaton')
else:
    print('both')
