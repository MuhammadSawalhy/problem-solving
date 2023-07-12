import sys


def solve():
    n, e = list(map(int, sys.stdin.readline().split()))
    enemies = []
    for _ in range(n + 1):
        enemies.append([])

    for _ in range(e):
        f, s = list(map(int, sys.stdin.readline().split()))
        enemies[f].append(s)
        enemies[s].append(f)

    print(enemies, file=sys.stderr)

    ans = 0
    for i in range(1, n + 1):
        print(file=sys.stderr)
        if len(enemies[i]) == 0:
            continue
        # cycle with odd number of players can't be split into two teams
        # we have to make one of the players set on the bench
        ans += follow(i, enemies, i) % 2
    return ans + (n - ans) % 2


def follow(i, enemies, t, depth = 0):
    depth += 1
    print(i, end=" ", file=sys.stderr)
    if len(enemies[i]) == 0:
        return 0
    j = enemies[i].pop()
    if i in enemies[j]:
        enemies[j].remove(i)
    if j == t:
        return depth
    return follow(j, enemies, t, depth)


print(solve())
