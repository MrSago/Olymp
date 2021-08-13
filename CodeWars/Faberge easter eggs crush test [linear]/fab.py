
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

