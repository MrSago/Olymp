
accord = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]

n, X = input().split() 
n = int(n)
X = int(X)

text = []
acc = []

for i in range(0, n):
    if (i % 2 == 0):
        acc.append(input().split())
    else:
        text.append(input())

for i in range(0, len(acc)):
    for j in range(0, len(acc[i])):
            acc[i][j] = accord[abs(((accord.index(acc[i][j])) + X) % len(accord))]
j = 0
k = 0
for i in range(0, n):
    if (i % 2 == 0):
        s = ""
        for m in acc[j]:
            s += m + " "
        print(s)
        j += 1
    else:
        print(text[k])
        k += 1

