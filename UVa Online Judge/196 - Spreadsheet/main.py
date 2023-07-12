import math
import sys

sheet = dict()


def coor_to_key(i, j):
    key = ""
    while j:
        key = chr(ord('A') + (j - 1) % 26) + key
        j = (j - 1) // 26
    key += str(i)
    return key


def val(key):
    v = sheet[key]
    if isinstance(v, int):
        return v
    if v[0] == "=":
        v = sum(val(k) for k in v[1:].split("+"))
        sheet[key] = v
    else:
        sheet[key] = int(v)
    return sheet[key]


def solve():
    c, r = list(map(int, sys.stdin.readline().split()))
    for i in range(1, r + 1):
        row = input().split()
        for j in range(1, c + 1):
            sheet[coor_to_key(i, j)] = row[j - 1]

    for i in range(1, r + 1):
        for j in range(1, c + 1):
            print(val(coor_to_key(i, j)), end=("\n" if j == c else " "))


if __name__ == "__main__":
    # sys.stdin = open("main_input0.txt", 'r')
    sys.setrecursionlimit(1000000000)
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()

