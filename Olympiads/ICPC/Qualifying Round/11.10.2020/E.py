
lens = int(input())
n = list(input())
k = 0
m = list()
for i in range(0, lens-1):
    if n[i] == n[i+1]:
        k += 1
    else:
        while k != 0:
            m.append(k)
            k -= 1
        m.append(0)
    if i == lens-2:
        while k != 0:
            m.append(k)
            k -= 1
for i in range(len(m)):
    print(m[i])

