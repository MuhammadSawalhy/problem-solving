import sys
import math


def solve():
    n, m = list(map(int, sys.stdin.readline().split()))
    faqs = []
    q = []

    for _ in range(n):
        faqs.append(set(input().lower().split()))

    for _ in range(m):
        q.append(set(input().lower().split()))

    for qq in q:
        # qq: set
        ma = []
        for i in range(n):
            if len(qq.intersection(faqs[i])) == len(qq):
                ma.append(i + 1)

        print(len(ma), end="")
        for m in ma:
            print(" " + str(m), end="")
        print()


solve()
