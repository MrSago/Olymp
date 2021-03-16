"""
ID: deadly51
TASK: dualpal
LANG: PYTHON3
"""
def to_base(n, tob):
    n = int(n)
    alph = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if n < tob:
        return alph[n]
    return to_base(n // tob, tob) + alph[n % tob]

def pal(n):
    t = str(n)
    for i in range(len(t)):
        if t[i] != t[-i-1]:
            return False
    return True


with open("dualpal.in", "r") as file:
    N, S = [int(x) for x in file.readline().strip().split()]
temp = []
i = S + 1
while True:
    if N == 0:
        break
    counter = 0
    for j in range(2, 11):
        if pal(to_base(i, j)):
            counter += 1
            if counter == 2:
                temp.append(str(i))
                break
    if counter == 2:
        N -= 1
    i += 1
with open("dualpal.out", "w") as file:
    file.write("\n".join(temp)+"\n")
    