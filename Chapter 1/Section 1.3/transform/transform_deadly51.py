"""
ID: deadly51
TASK: transform
LANG: PYTHON3
"""
with open("transform.in", "r") as file:
    n = int(file.readline().strip())
    start = [file.readline().strip() for i in range(n)]
    end = [file.readline().strip() for i in range(n)]


def compare(start, end):
    for i in range(len(start)):
        for j in range(len(start)):
            if start[i][j] != end[i][j]:
                return False
    return True


def rot90(m, n):
    res = []
    temp = []
    for i in range(n-1, -1, -1):
        for j in m:
            temp.append(j[i])
        res.append("".join(temp))
        temp = []
    return res


def refl(m, n):
    result = []
    for i in range(n):
        result.append(m[i][::-1])
    return result


def combine(start, end, n):
    return compare(rot90(refl(start, n), n), end) or compare(rot90(rot90(refl(start, n), n), n), end) or compare(rot90(rot90(rot90(refl(start, n), n), n), n), end)


result = 0

if compare(rot90(rot90(rot90(start, n), n), n), end):
    result = 1
elif compare(rot90(rot90(start, n), n), end):
    result = 2
elif compare(rot90(start, n), end):
    result = 3
elif compare(refl(start, n), end):
    result = 4
elif combine(start, end, n):
    result = 5
elif compare(start, end):
    result = 6
else:
    result = 7

with open("transform.out", "w") as file:
    file.write(str(result)+"\n")