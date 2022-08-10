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
template <class T> std::ostream& operator <<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  if (v.size()) os << v[0];
  for (typename std::vector<T>::const_iterator i = v.begin() + 1; i < v.end(); i++)
    os << ", " << *i;
  os << "]";
  return os;
}
#endif

template <class T> inline bool ckmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> inline bool ckmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> inline void clear(T *arr, int val, int n) { for (int i = 0; i < n; arr[i++] = val); }
// clang-format on

typedef long long ll;
typedef unsigned long long ull;

const int maxn = pow(2, 31) - 1;
int t_case;
ull n;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
  cin >> t_case;
  int h1, h2, h3;

  while (t_case--) {
    cin >> n;
    h2 = ceil(n / 3.0);
    h1 = h2 + 1;
    h3 = n - (h1 + h2);
    if (h3 == 0) {
      h2--;
      h3++;
    }
    std::cout << h2 << " " << h1 << " " << h3 << std::endl;
  }

  return 0;
}
