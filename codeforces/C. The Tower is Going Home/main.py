import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

# sys.setrecursionlimit(10000)

def values(): return tuple(map(int, sys.stdin.readline().split()))
def inlst(): return [int(i) for i in sys.stdin.readline().split()]
def inp(): return int(sys.stdin.readline())
def inpstr(): return sys.stdin.readline().strip()
def words(): return [i for i in sys.stdin.readline().split()]
def chars(): return list(sys.stdin.readline().strip())



def solve():
    n, m = values()

    vert = []
    for _ in range(n):
        vert.append(inp())

    vert = sorted(vert)
    vert.append(1e9)
    hori = []

    for _ in range(m):
        x1, x2, _ = values()
        if x1 == 1:
            hori.append(x2)

    n = len(vert)
    m = len(hori)
    vert_inc = [0] * n
    hori = sorted(hori)
    j, i = n - 1, m - 1

    while j >= 0:
        while i >= 0 and hori[i] >= vert[j]:
            i -= 1
        vert_inc[j] = m - 1 - i
        j -= 1

    ans = 2e6
    for rv in range(0, n):
        ans = min(ans, rv + vert_inc[rv])

    print(ans)


if __name__ == "__main__":
    # sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    solve()
