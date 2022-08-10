import sys
import math

from itertools import permutations, combinations


def solve():
    s = input()
    ss = ""
    for c in s:
        if c != " ":
            ss += c
    ss = sorted(ss)
    dic = []

    n = int(sys.stdin.readline())

    for _ in range(n):
        w = input()
        dic.append(w)

    ans = []
    for i in range(1, 8):
        coms = combinations(dic, i)
        for c in coms:
            __ss = "".join(c)
            __ss = sorted(__ss)
            if (__ss == ss):
                for p in permutations(c):
                    ans += [" ".join(p)]

    ans = sorted(ans)

    for a in ans:
        print(a)


solve()
