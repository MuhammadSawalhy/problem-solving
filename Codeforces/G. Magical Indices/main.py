import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os


def values(): return tuple(map(int, sys.stdin.readline().split()))


def inlst(): return [int(i) for i in sys.stdin.readline().split()]


def inp(): return int(sys.stdin.readline())


def inpstr(): return sys.stdin.readline().strip()


def words(): return [i for i in sys.stdin.readline().split()]


def chars(): return list(sys.stdin.readline().strip())


def solve():
    n = inp()
    a = values()
    l = [0] * n
    b = [0] * n
    b[0] = a[0]
    l[-1] = a[-1]
    for i in range(1, n):
        b[i] = max(b[i - 1], a[i])
    for i in range(n - 2, -1, -1):
        l[i] = min(l[i + 1], a[i])
    cnt = 0
    for i in range(1, n - 1):
        if a[i] >= b[i] and a[i] <= l[i]:
            cnt += 1
    print(cnt)


if __name__ == "__main__":
    sys.setrecursionlimit(10000000)
    sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    for i in range(inp()):
        solve()
