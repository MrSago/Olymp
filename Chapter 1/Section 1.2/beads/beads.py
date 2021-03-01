# Doesn't work
"""
ID: deadly51
TASK: beads
LANG: PYTHON3
"""
def all_the_same(elements):
    return len(set(elements)) <= 1


def to_list(n, string):
    result = []
    temp = []
    try:
        for i in range(n):
            temp.append(string[i])
            if string[i] != string[i+1]:
                result.append("".join(temp))
                temp = []
    except IndexError:
        if temp != []:
            result.append("".join(temp))
    return result + result


def sequencing(list):
    result = []
    if all_the_same(list):
        return [len(list[0])]
    nw = "w"
    for i in range(len(list)):
        if "w" not in list[i]:
            nw = list[i][0]
            break
    temp = [list[0]]
    checker = 1
    for i in range(1, len(list)):
        if nw not in list[i] and "w" not in list[i]:
            result.append("".join(temp))
            if "w" in list[i-1] and checker:
                temp = [list[i-1]]
                checker = 0
            else:
                temp = []
                checker = 1
            nw = list[i][0]
        temp.append(list[i])
    print(" ".join(result))
    return result


def find_max(n, string):
    numbers = sequencing(to_list(n, string))
    if len(numbers) == 1:
        return str(numbers[0])
    max_n = 0
    for i in range(len(numbers)//2-1,len(numbers)-1):
        temp = len(f"{numbers[i]}{numbers[i+1]}")
        max_n = max(max_n, temp)
    return(str(max_n))


with open("beads.in", "r") as fin:
    n = int(fin.readline().strip())
    necklace = fin.readline().strip()
    with open("beads.out", "w") as fout:
        fout.write(find_max(n, necklace) + "\n")