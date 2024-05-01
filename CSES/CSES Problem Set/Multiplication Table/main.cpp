// ﷽
// https://cses.fi/problemset/task/2422

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

    int target = n * n / 2 + 1; // count of number less than the middle
    int l = 0, r = n * n + 2;
    while (r - l > 1) {
        int x = (r + l) / 2;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            // max y such that y * i <= x, assume y * i = x
            int y = min(n, x / i);
            count += y;
        }
        debug(x, count);
        bool ok = count >= target;
        if (ok) {
            r = x;
        } else {
            l = x;
        }
    }

    cout << r << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
