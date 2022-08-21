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


mod = 1000000007


def solve():
    n, k = values()
    tree = [[] for _ in range(n)]
    for i in range(n):
        p = inp()
        tree[p].append(i)

    ans = k
    for


if __name__ == "__main__":
    sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    solve()
