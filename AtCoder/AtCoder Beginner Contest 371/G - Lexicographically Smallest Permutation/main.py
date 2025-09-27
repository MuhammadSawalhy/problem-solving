from math import gcd


N = int(input())
P = [int(x) - 1 for x in input().split()]
A = list(map(int, input().split()))

used = [False for i in range(N)]

# Based on the results so far, we know that the number of operations equals `ans` modulo `peeriod`.
period = 1
ans = 0

result = [0 for i in range(N)]

for i in range(N):
    if not used[i]:
        # Enumerate the cycle containing `i`
        cycle = [i]
        while P[cycle[-1]] != i:
            used[P[cycle[-1]]] = True
            cycle.append(P[cycle[-1]])

        # Minimize `A[i]`
        L = len(cycle)
        # There are `L / gcd(L, period)` choices
        choose = L // gcd(L, period)

        # Pick the minimum among the choices
        offset = min((A[cycle[(ans + i * period) % L]], i) for i in range(choose))[1]

        # Update the answer
        ans += offset * period
        period *= choose

        # Find the array of the answers
        for i in range(L):
            result[cycle[i]] = A[cycle[(i + ans) % L]]

print(*result)
