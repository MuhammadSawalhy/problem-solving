import math


def shift(s) -> int:
    for i in range(1, len(s)):
        if s == s[i:] + s[:i]:
            return i
    return len(s)


def solve():
    n = int(input())
    s = input()
    p = [int(x) - 1 for x in input().split()]
    vis = [False] * n
    ans = 1

    # for example:
    # ababab
    # 3 2 5 4 1
    #
    # we will take these cycles
    # 1 -> 3 -> 5
    # 2 -> 4
    #
    # get the lcm of their required operations to return back as it was

    for i in range(n):
        if vis[i]:
            # because num of operations for 1 -> 3 -> 5 is the same for 3 -> 5 -> 1
            # we should take only one the cycle independent of the beginning point
            continue

        ss = ''
        j = i
        ss += s[j]
        vis[j] = True
        j = p[j]
        # we will never come across a vis[j] == True here,
        # all the remaning elements are not touched before
        # think about it
        while j != i:
            ss += s[j]
            vis[j] = True
            j = p[j]

        ln = shift(ss)
        ans = ans * ln // math.gcd(ans, ln)

    print(ans)


t = int(input())
for _ in range(t):
    solve()
