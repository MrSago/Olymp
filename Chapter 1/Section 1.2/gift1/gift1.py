"""
ID: deadly51
TASK: gift1
LANG: PYTHON3
"""
with open("gift1.in", "r") as fin:
    np = int(fin.readline().strip())
    members = {}
    for i in range(np):
        members[fin.readline().strip()] = 0
    while True:
        name = fin.readline().strip()
        if len(name) == 0:
            break
        bank, times = [int(x) for x in fin.readline().strip().split()]
        if times != 0:
            members[name] -= bank
            how_much = bank//times
            members[name] += bank%times
            for i in range(times):
                members[fin.readline().strip()] += how_much
    with open("gift1.out", "w") as fout:
        fout.write("")
    with open("gift1.out", "a") as fout:
        for i in members:
            fout.write(f"{i} {members[i]}\n")














