import sys
import math


def solve():
    while True:
        try:
            n = int(input())
            print(n, file=sys.stderr)
            ans = 0
            i = 0
            ok = True
            while n != 0:
                if ((int(n) - 1) % 3 != 0 and int(n) % 3 != 0):
                    ok = False
                    break

                if n % 3 == 1:
                    ans += 2 ** i
                    n -= 1
                n /= 3
                i += 1
            if not ok:
                print(-1)
            else:
                print(ans)
        except EOFError:
            break


# sys.stdin = open("main_input0.txt", 'r')
t = int(sys.stdin.readline())
for _ in range(t):
    solve()
