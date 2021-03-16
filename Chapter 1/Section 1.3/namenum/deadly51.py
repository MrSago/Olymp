"""
ID: deadly51
TASK: namenum
LANG: PYTHON3
"""
with open("namenum.in", "r") as file:
    number = file.readline().strip()
    size = len(number)
with open("dict.txt") as file:
    dicti = [x.strip() for x in file.readlines()]

letters = {2: "ABC", 5: "JKL", 8: "TUV",
          3: "DEF", 6: "MNO", 9: "WXY",
          4: "GHI", 7: "PRS"}


words = []
def func(name, number, i):
    if i == len(number):
        for j in dicti:
            if name == j:
                words.append(name)
        return
    
    for z in letters[int(number[i])]:
        temp = name+z
        for j in dicti:
            if j.startswith(temp):
                func(temp, number, i+1)
                break


func("", number, 0)
if not words:
    words.append("NONE")
with open("namenum.out", "w") as file:
    for i in range(len(words)):
        file.write(f"{words[i]}\n")