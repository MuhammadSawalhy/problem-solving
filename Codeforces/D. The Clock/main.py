import sys


def isit(h, m):
    m = m % 10 * 10 + int(m / 10)
    return m == h


def solve():
    i = input().split()
    h, m = map(int, i[0].split(":"))
    h1, m1 = h, m
    x = int(i[1])

    cnt = 0

    hs = int(x / 60)
    ms = x % 60

    while True:
        if isit(h, m):
            cnt += 1

        h += hs
        h %= 24
        m += ms

        if m > 59:
            m %= 60
            h += 1
            h %= 24

        if h1 == h and m1 == m:
            print(cnt)
            break


# sys.stdin = open("main_input0.txt", 'r')
t = int(sys.stdin.readline())
for _ in range(t):
    solve()
