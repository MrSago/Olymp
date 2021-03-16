"""
ID: deadl51
TASK: crypt1
LANG: PYTHON3
"""
with open("crypt1.in", "r") as file:
    N = int(file.readline().strip())
    crypts = [int(x) for x in file.readline().strip().split()]  

def isValid(*args):
    args = [str(x) for x in args]
    for i in args:
        for j in i:
            if int(j) not in crypts:
                return False
    return True

answer = 0
for i in range(100, 1000):
    for j in range(10, 100):
        num1, num2, part1, part2, prod1 = i, j, i * (j % 10), i * (j // 10), i * j
        if isValid(num1, num2, part1, part2, prod1) and part1 <= 999 and part2 <= 999 and prod1 < 10000:
            answer += 1

with open("crypt1.out", "w") as file:
    file.write(f"{answer}\n")

