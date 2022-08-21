import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os
from queue import PriorityQueue

# sys.setrecursionlimit(10000)

def values(): return tuple(map(int, sys.stdin.readline().split()))
def inlst(): return [int(i) for i in sys.stdin.readline().split()]
def inp(): return int(sys.stdin.readline())
def inpstr(): return sys.stdin.readline().strip()
def words(): return [i for i in sys.stdin.readline().split()]
def chars(): return list(sys.stdin.readline().strip())

dist = []

def dijkstra(s, d):
    qu = PriorityQueue()
    qu.put((0, s))
    while not qu.empty():
        p = qu.get()
        i, j = p[1]
        if p[0] > dist[i][j]: continue

        i += 1
        if i < h and p[0] + shop[i][j] < dist[i][j]:
            qu.put((p[0] + shop[i][j], (i, j)))
            dist[i][j] = p[0] + shop[i][j]
        i -= 2
        if i >= 0 and p[0] + shop[i][j] < dist[i][j]:
            qu.put((p[0] + shop[i][j], (i, j)))
            dist[i][j] = p[0] + shop[i][j]
        i += 1
        j -= 1
        if j >= 0 and p[0] + shop[i][j] < dist[i][j]:
            qu.put((p[0] + shop[i][j], (i, j)))
            dist[i][j] = p[0] + shop[i][j]
        j += 2
        if j < w and p[0] + shop[i][j] < dist[i][j]:
            qu.put((p[0] + shop[i][j], (i, j)))
            dist[i][j] = p[0] + shop[i][j]

    return dist[d[0]][d[1]]


def solve(w, h):
    global shop, dist
    shop = []
    start = None
    dest = None
    dist = []
    for i in range(h):
        dist.append([1e10] * w)
        shoprow = []
        shop.append(shoprow)
        row = chars()
        for j in range(w):
            if row[j] == 'S':
                start = (i, j)
                shoprow.append(0)
            elif row[j] == 'D':
                dest = (i, j)
                shoprow.append(0)
            elif row[j] == 'X':
                shoprow.append(1e10) # infinity
            else:
                shoprow.append(int(row[j]))

    print(dijkstra(start, dest))


if __name__ == "__main__":
    # sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    while True:
        global w, h
        w, h = values()
        if w == 0:
            break
        solve(w, h)
        input()
