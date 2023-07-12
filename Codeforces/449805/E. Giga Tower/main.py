# ﷽
import sys

input = lambda: sys.stdin.readline().strip()

def inlst():return [int(i) for i in input().split()]

def luk(n):
      return '8' in str(n) 

def solve():
    n=int(input())
    ans=float('inf')
    for i in range(1,11):
          if luk(n+i) :
                ans=i
                break
    print(ans)

if __name__ == "__main__":
    # for i in range(int(input())):
        solve()
