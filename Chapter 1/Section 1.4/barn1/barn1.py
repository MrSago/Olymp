"""
ID: deadly51
TASK: barn1
LANG: PYTHON3
"""
with open("barn1.in", "r") as file:
    M, S, C = [int(x) for x in file.readline().strip().split()]
    stalls = [int(x.strip()) for x in file.readlines()]
    stalls.sort()
if len(stalls) < M:
    with open("barn1.out", "w") as file:
        file.write(f"{len(stalls)}\n")
        raise SystemExit
if M == 1:
    with open("barn1.out", "w") as file:
        file.write(f"{stalls[-1]-stalls[0]+1}\n")
        raise SystemExit



quantity = [0 for i in range(M-1)]
distances = [stalls[i]-stalls[i-1] for i in range(1, len(stalls))]

for i in range(len(distances)):
    for j in range(len(quantity)):
        if distances[i] > quantity[j]:
            quantity = quantity[1:len(quantity)] + [distances[i]]
            quantity.sort()
            break

temp = []
for i in range(len(distances)-1, 0, -1):
    for j in range(len(quantity)):
        if distances[i] == quantity[j]:
            quantity = quantity[:j] + quantity[j+1:]
            temp.append(i)
            break

answer = 0
temp.sort()
temp = [-1] + temp + [len(distances)]
for i in range(1, len(temp)):
    answer += stalls[temp[i]] - stalls[temp[i-1]+1]
answer += M
with open("barn1.out", "w") as file:
    file.write(f"{answer}\n")