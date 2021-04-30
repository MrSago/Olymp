
"""
ID: sagosag1
TASK: frac1
LANG: PYTHON3
"""

from fractions import Fraction

with open("frac1.in", "r") as fin:
    N = int(fin.readline())

s = set()
for i in range(N, 1, -1):
    for j in range(1, i):
        s.add(Fraction(j, i))

res = sorted(s)

with open("frac1.out", "w") as fout:
    fout.write("0/1\n")
    for i in res:
        fout.write(f"{i}\n")
    fout.write("1/1\n")

