a, b = list(map(int, input().split())), list(map(int, input().split()))
n = int(input())
print('YES' if  all(
    (
        a[i] // 5 + (1 if a[i] % 5 else 0) +
        b[i] // 10 + (1 if b[i] % 10 else 0)) <= n 
    for i in range(3)) else 'NO')
