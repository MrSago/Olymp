"""
ID: deadly51
TASK: milk2
LANG: PYTHON3
"""
with open("milk2.in", "r") as file:
    n = int(file.readline().strip())
    info = [[int(x) for x in i.strip().split()] for i in file.readlines()]
info.sort()
more_continuous = 0
max_idle_time = 0

start = info[0][0]
end = info[0][1]
if len(info) <= 1:
    more_continuous = start
    end = 0
else:
    for i in range(len(info)):
        if info[i][0] > end:
            start = info[i][0]
            max_idle_time = max(max_idle_time, info[i][0] - end)
        end = max(end, info[i][1])
        more_continuous = max(more_continuous, end - start)
with open("milk2.out", "w") as file:
    file.write(f"{more_continuous} {max_idle_time}\n")