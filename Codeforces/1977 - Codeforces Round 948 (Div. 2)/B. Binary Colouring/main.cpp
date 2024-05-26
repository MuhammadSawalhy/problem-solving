// ﷽
// https://codeforces.com/contest/1977/problem/B

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
    int x;
    cin >> x;

    bitset<32> y(x);

    vector<int> ans(32);

    debug(x);
    for (int i = 0; i < 31; i++) {
        ans[i] = y[i];
        if (y[i] == 0) continue;
        int j = (~y)._Find_next(i);
        if (j > i + 1) {
            for (int k = i + 1; k < j; k++) {
                y[k] = 0;
            }
            y[j] = 1;
            ans[i] = -1;
        }
    }

    cout << 32 << endl;
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
