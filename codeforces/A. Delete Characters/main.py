import sys
import math


def solve():
    s = input()
    n = int(input())
    cs = []

    for _ in range(n):
        c = input()
        cs.append(c)

    for c in s:
        if c not in cs:
            print(c, end="")

    print()


solve()

