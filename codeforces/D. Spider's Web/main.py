import collections
import heapq
import sys
import math
import itertools
import bisect
import os


def values():
    return tuple(map(int, sys.stdin.readline().split()))


def inplst():
    return [int(i) for i in sys.stdin.readline().split()]


def inp():
    return int(sys.stdin.readline())


def inpstr():
    return sys.stdin.readline().strip()


def words():
    return sys.stdin.readline().split()


def chars():
    return list(sys.stdin.readline().strip())


def solve():
    N = inp()
    sectors = []
    for i in range(N):
        sector_bridges = values()[1:]
        sectors.append(sorted(sector_bridges))

    ans = 0

    for i in range(N):
        pi, ni = 0, 0
        ps, ns = sectors[(i - 1 + N) % N], sectors[(i + 1) % N]
        s = sectors[i]
        for j in range(len(s) - 1):
            p, n = 0, 0
            while pi < len(ps) and ps[pi] < s[j + 1]:
                if s[j] <= ps[pi] <= s[j + 1]:
                    p += 1
                pi += 1
            if pi < len(ps) and s[j] <= ps[pi] <= s[j + 1]:
                p += 1

            while ni < len(ns) and ns[ni] < s[j + 1]:
                if s[j] <= ns[ni] <= s[j + 1]:
                    n += 1
                ni += 1
            if ni < len(ns) and s[j] <= ns[ni] <= s[j + 1]:
                n += 1

            if n != p:
                ans += 1

    print(ans)


if __name__ == "__main__":
    if os.path.exists('/home/ms/myp/problem-solving/input'):
        sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    sys.setrecursionlimit(10000000)
    solve()
