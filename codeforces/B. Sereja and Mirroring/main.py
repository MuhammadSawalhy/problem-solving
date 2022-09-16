import collections
import heapq
import sys
import math
import itertools
import bisect
import os


def values():
    return tuple(map(int, sys.stdin.readline().split()))


def inp():
    return int(sys.stdin.readline())


def inpstr():
    return sys.stdin.readline().strip()


def words():
    return sys.stdin.readline().split()


def chars():
    return list(sys.stdin.readline().strip())


def check_sym(mat, end):
    if end & 1:
        return False
    for i in range(end // 2):
        if mat[end // 2 - 1 - i] != mat[end // 2 + i]:
            return False
    return True


def solve():
    n, m = values()
    mat = []
    for i in range(n):
        row = values()
        r = 0
        for j in range(m):
            r |= row[j] << j
        mat.append(r)

    end = n

    while check_sym(mat, end):
        end //= 2

    print(end)


if __name__ == "__main__":
    # if os.path.exists('/home/ms/myp/problem-solving/input'):
    #     sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    sys.setrecursionlimit(10000000)
    solve()
