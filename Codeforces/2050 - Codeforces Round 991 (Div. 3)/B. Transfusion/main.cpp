// ﷽
// https://codeforces.com/contest/2050/problem/B

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    int sum[2]{};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i & 1] += a[i];
    }

    if (sum[0] % ((n + 1)/ 2) == 0 && sum[1] % (n / 2) == 0 && sum[0] / ((n + 1)/ 2) == sum[1] / (n / 2)) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
