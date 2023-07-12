import sys


def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    x = max(a)

    ans = []
    while x > 0:
        for i in range(n):
            if a[i] == x:
                if len(ans) > 1 and ans[-1] == ans[-2]:
                    temp = ans.pop()
                    ans.append(i + 1)
                    ans.append(temp)
                else:
                    ans.append(i + 1)

                a[i] -= 1

        if len(ans) > 1 and ans[-1] == ans[-2]:
            print(-1)
            return

        x -= 1

    print(" ".join(map(str, ans)))


solve()
