"""
ID: deadly51
TASK: ride
LANG: PYTHON3

"""
def prod(s):
    temp = 1
    for i in s:
        temp *= i
    return temp

def convert(s):
    return [ord(i)%32 for i in s]

def compare(s1, s2):
    return "GO\n" if prod(convert(s1)) %47 == prod(convert(s2)) %47 else "STAY\n"


fin = open("ride.in","r")
fout = open("ride.out", "w") 
str1 = fin.readline().strip()
str2 = fin.readline().strip()
fin.close()
fout.write(compare(str1, str2))
fout.close()