
for i in range (0, int(input())):
    n = int(input())
    m = [int(i) for i in range(n, 0, -1)]
    if (n % 2 != 0):
        a = m[n//2]
        b = m[n//2 + 1]
        m[n//2] = b
        m[n//2 + 1] = a
    for i in m: print(i, end=' ')
    print('')

