import math

n = int(input())

dp = [(0, 1)] * 101

f = list(map(int, input().split()))


def add(fraca: tuple[int, int], fracb: tuple[int, int]):
    x = fraca[0] * fracb[1] + fracb[0] * fraca[1]
    y = fraca[1] * fracb[1]
    g = math.gcd(x, y)
    return (x // g, y // g)


def mul(fraca: tuple[int, int], fracb: tuple[int, int]):
    x = fraca[0] * fracb[0]
    y = fraca[1] * fracb[1]
    g = math.gcd(x, y)
    return (x // g, y // g)

ans = (0, 1)

for i in range(n):
    for x in range(1, f[i] + 1):
        ans = add(ans, mul(dp[x], (1, f[i])))
        dp[x] = add(dp[x], (f[i] - x, f[i]))

print(f"{ans[0] / ans[1]:.6f}")

