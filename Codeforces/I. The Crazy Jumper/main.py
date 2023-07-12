import collections
import heapq
import sys
import math
import itertools
import bisect


def values(): return tuple(map(int, sys.stdin.readline().split()))
def inlst(): return [int(i) for i in sys.stdin.readline().split()]
def inp(): return int(sys.stdin.readline())
def inpstr(): return sys.stdin.readline().strip()
def words(): return [i for i in sys.stdin.readline().split()]
def chars(): return list(sys.stdin.readline().strip())


def dp(i):
    if memo[i] != -1:
        return memo[i]
    if i >= n - 1:
        return 0
    r = dp(i + 1) + 1
    p = pos[c[i]]
    next = bisect.bisect_right(p, i)
    if next < len(p):
        b = dp(p[next]) + 1
        r = min(r, b)
    memo[i] = r
    return r


def solve():
    global n, c, memo, pos
    n = inp()
    c = values()
    pos = {}
    memo = [-1] * n
    for i in range(n):
        if c[i] not in pos:
            pos[c[i]] = []
        pos[c[i]].append(i)
    print(dp(0))


if __name__ == "__main__":
    sys.setrecursionlimit(1000000000000)
    sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    for i in range(inp()):
        solve()
