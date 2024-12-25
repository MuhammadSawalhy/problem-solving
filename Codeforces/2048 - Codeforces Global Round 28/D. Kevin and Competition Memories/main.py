import bisect

def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    A = sorted(a[1:])
    for i in range(m):
        if b[i] <= a[0]:
            b[i] = 1
        else:
            j = n - 1 - bisect.bisect_left(A, b[i])
            b[i] = j + 1
    b.sort()
    for k in range(1, m + 1):
        sum_ = 0
        for j in range(k - 1, m, k):
            sum_ += b[j]
        print(sum_, end=' ')
    print()

def main():
    T = int(input())
    for _ in range(T):
        solve()

main()

