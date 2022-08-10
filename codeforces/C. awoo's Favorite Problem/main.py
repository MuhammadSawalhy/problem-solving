def solve():
    n = int(input())
    s = input()
    t = input()

    def getc(c, s, i):
        for j in range(i, len(s)):
            if c == s[j]:
                return s[0:j] + s[j + 1:]  # remove c
            if c == "c" and s[j] != "b":
                return ""
            if c == "b" and s[j] != "a":
                return ""
        return ""

    for i in range(n):
        if s[i] != t[i]:
            if i == n - 1:
                print("NO")
                return
            if t[i] == "a":
                print("NO")
                return
            c = getc(t[i], s, i)
            if not c:
                print("NO")
                return
            s = " " + c  # compensate t[i] removal by increasing the len of s

    print("YES")


# sys.stdin = open("main_input0.txt", 'r')
t = int(input())
for _ in range(t):
    solve()
