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
    n, q = values()
    w = inpstr()

    counts = [0] * 26
    counts_l = []

    for i in range(n):
        c = ord(w[i]) - ord('a')
        counts[c] += 1
        counts_l.append(counts.copy())

    while q:
        q -= 1
        l, r, c = words()
        l = int(l) - 1
        r = int(r)
        c = ord(c[0]) - ord('a')
        cnt = 0
        lr = int(r / n) - int(l / n) + 1
        cnt += lr * counts[c]
        if l % n != 0:
            cnt -= counts_l[l % n - 1][c]
        cnt -= counts[c]
        if r % n != 0:
            cnt += counts_l[r % n - 1][c]

        print(cnt)


if __name__ == "__main__":
    sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    for i in range(inp()):
        solve()
