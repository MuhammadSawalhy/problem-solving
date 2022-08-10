// TODO: think about this later

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define debug1(x) cerr << #x << ": " << x << endl
#define debug2(x, y) cerr << #x << ", " << #y << ": " << x << ", " << y << endl
#else
// and placeholder
#define debug1(...) 0
#define debug2(...) 0
#endif

typedef long long ll;

template <class T> inline bool ckmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}

template <class T> inline bool ckmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}

template <class T> inline void clear(T *arr, int siz, int val = 0) {
  memset(arr, val, sizeof(T) * (siz + 1));
}

const int maxn = INT_MAX;
int n, t_case;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t_case;
  string s;
  char c;
  while (t_case--) {
    c = 0;
    cin >> n;
    n = n << 1 | 1; // * 2 + 1

    while (n--) {
      cin >> s;
      debug1(s);
      // bitwise trick to get the only char that appeared odd times
      // the even repeated chars will vanish
      for (char ch : s) c ^= ch;
    }

    std::cout << c << std::endl;
  }

  return 0;
}
