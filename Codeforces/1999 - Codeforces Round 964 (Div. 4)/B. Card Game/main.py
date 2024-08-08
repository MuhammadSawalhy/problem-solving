def count_wins(a1, a2, b1, b2):
    # print(a1, a2, b1, b2)
    wins = 0
    a = [a1, a2]
    b = [b1, b2]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                for l in range(2):
                    if i == j or k == l:
                        continue
                    if a[i] >= b[k] and a[j] > b[l] or a[i] > b[k] and a[j] >= b[l] :
                        wins += 1

    return wins


t = int(input())
for _ in range(t):
    a1, a2, b1, b2 = map(int, input().split())
    print(count_wins(a1, a2, b1, b2))

