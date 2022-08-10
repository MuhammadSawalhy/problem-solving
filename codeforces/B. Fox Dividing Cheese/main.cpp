#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef LOCAL
// and placeholder
#define debug1(...) 0
#define debug2(...) 0
#define debug_arr(...) 0
#else
#define debug1(x)    cerr << #x << ": " << x << endl
#define debug2(x, y) cerr << #x << ", " << #y << ": " << x << ", " << y << endl
#define debug_arr(arr, n) cerr << #arr << ": " << arr[0]; for (int i = 1; i < n; i++) cerr << ", " << b[i]; cerr << endl
#endif

template <class T> inline bool ckmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> inline bool ckmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> inline void clear(T *arr, int val, int n) { for (int i = 0; i < n; arr[i++] = val); }
template <class T> std::ostream& operator <<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  if (v.size()) os << v[0];
  for (typename std::vector<T>::const_iterator i = v.begin() + 1; i < v.end(); i++)
    os << ", " << *i;
  os << "]";
  return os;
}
// clang-format on

typedef long long ll;

const int maxn = pow(2, 31) - 1;
ll a, b, ops = maxn;

vector<vector<int>> get_prime_factors(ll n) {
  vector<vector<int>> result;
  int r = 0;

  while (n % 2 == 0) {
    r++;
    n = n / 2;
  }

  if (r > 0)
    result.push_back({2, r});

  for (int i = 3; i <= sqrt(n); i += 2) {
    r = 0;
    while (n % i == 0) {
      r++;
      n = n / i;
    }
    if (r > 0)
      result.push_back({i, r});
  }

  if (n > 2)
    result.push_back({(int)n, 1});

  return result;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  auto aprimes = get_prime_factors(a);
  auto bprimes = get_prime_factors(b);

  std::cerr << aprimes << std::endl;
  std::cerr << bprimes << std::endl;

  int ops = 0;
  bool impossible = false;
  ll done = 1;
  for (auto ap : aprimes) {
    bool found = false;
    for (auto bp : bprimes) {
      if (bp[0] == ap[0]) {
        ops += abs(bp[1] - ap[1]);
        done *= ap[0];
        found = true;
      }
    }
    if (!found) {
      if (ap[0] == 2 || ap[0] == 3 || ap[0] == 5) {
        ops += ap[1];
        done *= ap[0];
      } else {
        impossible = true;
        break;
      }
    }
  }

  for (auto bp : bprimes) {
    if (done % bp[0] != 0) {
      if (bp[0] == 2 || bp[0] == 3 || bp[0] == 5) {
        ops += bp[1];
        done *= bp[0];
      } else {
        impossible = true;
        break;
      }
    }
  }

  if (impossible)
    std::cout << -1 << std::endl;
  else
    std::cout << ops << std::endl;

  return 0;
}
