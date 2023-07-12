import sys
import math
from datetime import *


def solve():
    n = int(sys.stdin.readline())
    if (n == 0):
        return False
    d = list(map(int, sys.stdin.readline().split()))
    cnt = 0
    cost = 0
    for _ in range(n - 1):
        pd = d
        d = list(map(int, sys.stdin.readline().split()))
        day = datetime(day=d[0], month=d[1], year=d[2])
        pday = datetime(day=pd[0], month=pd[1], year=pd[2])
        if (day - pday == timedelta(days=1)):
            cnt += 1
            cost += d[3] - pd[3]
    print(f"{cnt} {cost}")
    return True


while solve():
    pass
