import math


def inint():
    return int(input())


def inints():
    return map(int, input().strip().split())

# -----------------------------------------------------
# -----------------------------------------------------
# -----------------------------------------------------

a = b = c = d = 0

def fd(x: float):
    return a * x * x * x + b * x * x + c * x + d


def f(x: int):
    return a * x * x * x + b * x * x + c * x + d


def check(res: int):
    return res >= int(-1e9) and res <= int(1e9) and f(res) == 0


def sign(x: float):
    return -1 if x < 0 else 1


def BS(l: int, r: int) -> int:
    l -= 100
    r += 100

    sl = sign(fd(float(l)))
    sr = sign(fd(float(r)))
    if (sl == sr): return 1

    while r - l > 100:
        mid = (r + l) // 2
        if sign(fd(mid * 1.0)) == sl:
            l = mid
        else:
            r = mid

    for x in range(l - 1000, r + 1000):
        if check(x):
            return x

    return 1


def solve():
    global a, b, c, d
    a, b, c, d = inints()

    val = 4 * b * b - 12 * a * c

    if d == 0:
        print("Yes")
        print(0)
        return

    if val < 0:
        res = BS(int(-1e9), int(1e9))
        if check(res):
            print("Yes")
            print(res)
            return
    else:
        x1 = int((-2 * b - math.sqrt(val)) / 6.0 / a)
        x2 = int((-2 * b + math.sqrt(val)) / 6.0 / a)
        if x1 > x2:
            x1, x2 = x2, x1

        res = BS(int(-1e9), x1)
        if check(res):
            print("Yes")
            print(res)
            return

        res = BS(x1, x2)
        if check(res):
            print("Yes")
            print(res)
            return

        res = BS(x2, int(1e9))
        if check(res):
            print("Yes")
            print(res)
            return

    print("No")


for t in range(inint()):
    solve()
