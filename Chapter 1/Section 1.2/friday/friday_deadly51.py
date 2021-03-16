"""
ID: deadly51
TASK: friday
LANG: PYTHON3
"""
with open("friday.in", "r") as fin:
    years = int(fin.readline().strip())
    months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    days = [0 for _ in range(7)]
    day_counter = 1

    for year in range(1900, 1900+years):
        if year % 4 != 0 or (year % 100 == 0 and year % 400 != 0):
            months[1] = 28
        else:
            months[1] = 29
        for month in range(len(months)):
            for day in range(1, months[month]+1):
                if day == 13:
                    days[day_counter-1] += 1
                if day_counter == 7:
                    day_counter = 0
                day_counter += 1
    open("friday.out", "w").close()
    with open("friday.out", "a") as fout:
        fout.write(f"{days[5]} {days[6]} {days[0]} {days[1]} {days[2]} {days[3]} {days[4]}\n")
