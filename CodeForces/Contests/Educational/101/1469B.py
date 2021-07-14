
t = int(input())
for i in range(0, t):
    n = int(input())
    red = [int(i) for i in input().split()]
    m = int(input())
    blue = [int(i) for i in input().split()]
    
    red_max = ssum = 0
    for j in range(0, n):
        ssum += red[j]
        red_max = max(red_max, ssum)

    blue_max = ssum = 0
    for j in range(0, m):
        ssum += blue[j]
        blue_max = max(blue_max, ssum)
    
    print(red_max + blue_max)

