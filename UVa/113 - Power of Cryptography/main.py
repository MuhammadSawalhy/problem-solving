import sys
import os


def solve():
    n = int(input())
    p = int(input())
    print(round(pow(p,  1 / n)))


if __name__ == "__main__":
    # if os.path.exists('/home/ms/myp/problem-solving/input'):
    #     sys.stdin = open('/home/ms/myp/problem-solving/input', 'r')
    # sys.setrecursionlimit(100000)
    while True:
        try:
            solve()
        except:
            break
