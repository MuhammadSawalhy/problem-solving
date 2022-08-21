import sys
import math

memo = dict()
sheet = dict()


def coor_to_key(i, j):
    key = ""
    while j:
        key += chr(ord('A') + (j - 1) % 26)
        j = int(j / 26)
    key += str(i)
    return key


def val(key):
    if key in memo:
        return memo[key]
    v = sheet[key]
    if v[0] == "=":
        v = sum([val(k) for k in v[1:].split("+")])
    memo[key] = int(v)
    return memo[key]


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
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()
        if _ != t - 1:
            print()

