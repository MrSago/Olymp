
"""
    author: MrS4g0
    created: 13.08.2021 21:02:33
    kata link: https://www.codewars.com/kata/5976c5a5cd933a7bbd000029/train/python
"""

MOD = 998244353

inv = [0, 1]
for i in range(2, 80000 + 1):
        inv.append( (MOD - MOD // i) * inv[MOD % i] % MOD )

def height(n, m):
    ans, c = 0, 1
    m %= MOD
    for i in range(1, n + 1): 
        c = c * (m - i + 1) * inv[i] % MOD
        ans = (ans + c) % MOD
    return ans % MOD

