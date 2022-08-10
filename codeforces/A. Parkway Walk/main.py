def solve():
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    s = sum(a)
    print(max(0, s - m))


# sys.stdin = open("main_input0.txt", 'r')
t = int(input())
for _ in range(t):
    solve()
