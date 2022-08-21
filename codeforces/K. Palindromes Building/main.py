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
    print(values())


if __name__ == "__main__":
    sys.setrecursionlimit(100000000)
    sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    for i in range(inp()):
        solve()
