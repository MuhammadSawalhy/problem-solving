#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define int ull

const int MAX = 1e5 + 1;

int last;
int memo[MAX];
int last_twin;
short prime_memo[(int)2e7 + 20];


bool miller_rabin_ptest(ull n, int k = 7) {
  if (prime_memo[n] == 1)
    return true;
  if (prime_memo[n] == 2)
    return false;
  if (n < 2)
    return false;
  if (n == 2)
    return true;

  while (k--) {
    int a = rand() % (n - 2) + 2;
    int p = n - 1;
    int r = 1;

    while (p) {
      if (p & 1)
        r = r * a % n;
      a = a * a % n;
      p >>= 1;
    }

    if (r != 1) {
      prime_memo[n] = 2;
      return false;
    }
  }

  prime_memo[n] = 1;
  return true; // probably
}

void print(int s) {
  cout << "(" << memo[s] << ", " << memo[s] + 2 << ")" << endl;
}

void solve(int s) {
  while (last < s) {
    last_twin += 6;
    if (miller_rabin_ptest(last_twin) && miller_rabin_ptest(last_twin + 2)) {
      last++;
      memo[last] = last_twin;
    }

    last_twin += 2;
    if (miller_rabin_ptest(last_twin) && miller_rabin_ptest(last_twin + 2)) {
      last++;
      memo[last] = last_twin;
    }

    last_twin += 2;
    if (miller_rabin_ptest(last_twin) && miller_rabin_ptest(last_twin + 2)) {
      last++;
      memo[last] = last_twin;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  memo[1] = 3;
  memo[2] = 5;
  memo[3] = 11;
  memset(prime_memo, (short)0, sizeof(prime_memo));

  last = 3;
  last_twin = 11;

  solve(1e5);

  while (cin >> s) {
    solve(s);
    print(s);
  }

  return 0;
}
