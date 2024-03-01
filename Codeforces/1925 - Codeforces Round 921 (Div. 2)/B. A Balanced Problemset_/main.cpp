// ﷽
// https://codeforces.com/contest/1925/problem/B

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int x, n;
    cin >> x >> n;

    vector<int> factors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factors.push_back(i);
            if (i * i != x) {
                factors.push_back(x / i);
            }
        }
    }

    sort(rall(factors));
    for (int f: factors) {
        if (x / f >= n) {
            cout << f << endl;
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
