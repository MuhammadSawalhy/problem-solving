// ﷽
// https://codeforces.com/group/Rilx5irOux/contest/541731/problem/I

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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> m >> n;

    int ans = 0;

    if (m == 1) {
        cout << n * (n - 1) / 2 << endl;
        return;
    }

    int cur = 1;
    int d = 0;

    while (n) {
        int items = min(cur, n);
        n -= items;

        ans += items * d;

        d++;
        cur *= m;
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
