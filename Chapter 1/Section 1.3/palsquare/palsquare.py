"""
ID: deadly51
TASK: palsquare
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


with open("palsquare.in", "r") as file:
    B = int(file.readline().strip())
temp = []
for i in range(1, 301):
    a = to_base(i, B)
    t = to_base(i**2, B)
    if pal(t):
        temp.append(f"{a} {t}")

with open("palsquare.out", "w") as file:
    file.write("\n".join(temp)+"\n")
    