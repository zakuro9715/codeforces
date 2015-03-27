s = raw_input()
n = input()
for i in range(n):
  l, r = map(int, raw_input().split())
  t = s[l - 1: r]
  ans = 0
  st = 0
  for c in t:
    if c == '(':
      st += 1
    elif c == ')':
      if st > 0:
        ans += 2
        st -= 1
  print ans
