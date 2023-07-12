import sys
import itertools


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


def solve():
    n, l, r, x = values()
    c = sorted(values())
    ans = 0
    for i in range(2, n + 1):
        for com in itertools.combinations(c, i):
            s = sum(com)
            if l <= s <= r and max(com) - min(com) >= x:
                ans += 1
    print(ans)


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    solve()
