"""
ID: deadly51
TASK: milk
LANG: PYTHON3
"""
with open("milk.in", "r") as file:
    N, M = [int(x) for x in file.readline().strip().split()]
    farmers = []
    for i in range(M):
        farmers.append(file.readline().strip().split())

for i in farmers:
    for x in range(len(i)):
        i[x] = int(i[x])

farmers.sort()

# temp = [x[0]*x[1] for x in farmers]

sum = 0
for i in farmers:
    t = i[1]
    if N < t:
        sum += N*i[0]
        break
    else:
        sum += t*i[0]
    N -= i[1]
with open("milk.out", "w") as file:
    file.write(f"{sum}\n")