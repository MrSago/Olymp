
def height(n, m):
    ans, c = 0, 1
    for i in range(1, n + 1): 
        c = c * (m - i + 1) // i
        ans = (ans + c)
    return ans

