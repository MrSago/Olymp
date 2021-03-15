"""
ID: deadly51
TASK: combo
LANG: PYTHON3
"""
with open("combo.in", "r") as file:
    N = int(file.readline().strip())
    farmer = [int(x) for x in file.readline().strip().split()]
    master = [int(x) for x in file.readline().strip().split()]

array = [x for x in range(1, N+1)]
array = array[len(array)-2:] + array + array[:2]
gen1 = []
gen2 = []
for i in range(3):
    gen1.append(array[farmer[i]-1:farmer[i]+4])
for i in range(3):
    gen2.append(array[master[i]-1:master[i]+4])


def IsValid1(a, b, c):
    lst = [a, b, c]
    count = 0
    for i in range(3):
        if lst[i] in gen1[i]:
            count += 1
    if count == 3:
        return True
    return False


def IsValid2(a, b, c):
    lst = [a, b, c]
    count = 0
    for i in range(3):
        if lst[i] in gen2[i]:
            count += 1
    if count == 3:
        return True
    return False

answer = 0
cache = set([])
for i in range(1, 3):
    for a in locals().get(f"gen{i}")[0]:
        for b in locals().get(f"gen{i}")[1]:
            for c in locals().get(f"gen{i}")[2]:
                if locals().get(f"IsValid{i}")(a, b, c) and f"{a} {b} {c}" not in cache:
                    cache.add(f"{a} {b} {c}")
                    answer += 1

with open("combo.out", "w") as file:
    file.write(f"{answer}\n")
