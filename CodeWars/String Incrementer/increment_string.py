
"""
    author: MrS4g0
    created: 13.08.2021 14:15:06
    kata link: https://www.codewars.com/kata/54a91a4883a7de5d7800009c/train/python
"""

from regex import findall

def increment_string(strng):
    s = findall(r"\d+", strng)
    if (len(s) == 0):
        return strng + "1"
    s = s[-1]
    num = str(int(s) + 1)
    res = ""
    if (len(num) < len(s)):
        for i in range(len(s) - len(num)):
            res += "0"
    res += num
    return strng.replace(s, res)

