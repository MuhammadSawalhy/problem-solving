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
    print(values())


if __name__ == "__main__":
    if os.path.exists('/home/ms/myp/problem-solving/input'):
        sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    sys.setrecursionlimit(10000000)
    for i in range(inp()):
        solve()
