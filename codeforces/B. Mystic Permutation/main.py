for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l2 = sorted(l)

    if n == 1:
        print(-1)

    else:
        for i in range(n):
            if l2[i] == l[i]:
                if i == n-1:
                    l2[i], l2[i-1] = l2[i-1], l2[i]
                else:
                    l2[i], l2[i+1] = l2[i+1], l2[i]

        print(*l2)

