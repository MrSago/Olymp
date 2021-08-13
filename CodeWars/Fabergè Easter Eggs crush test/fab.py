
"""
    author: MrS4g0
    created: 13.08.2021 22:10:05
    kata link: https://www.codewars.com/kata/54cb771c9b30e8b5250011d4/train/python
"""

def height(n, m):
    ans, c = 0, 1
    for i in range(1, n + 1): 
        c = c * (m - i + 1) // i
        ans = (ans + c)
    return ans

