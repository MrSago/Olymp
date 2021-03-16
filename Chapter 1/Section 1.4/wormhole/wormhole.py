"""
ID: deadly51
TASK: wormhole
LANG: PYTHON3
"""
from io import UnsupportedOperation


with open("wormhole.in", "r") as file:
    N = int(file.readline().strip())
    holes =[x.strip().split() for x in file.readlines()]
    holes.sort()


answer = 0
used = []
temp = []
try:
    for i in range(N):
        temp.append(holes[i])
        if holes[i][0] != holes[i+1][0]:
            used.append(temp)
            temp = []
except IndexError:
    used.append(temp)

with open("wormhole.out", "w") as file:
    file.write(f"{answer}\n")




