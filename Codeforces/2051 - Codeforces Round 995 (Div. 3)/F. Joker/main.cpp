// ﷽
// https://codeforces.com/contest/2051/problem/F

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
    int n, m, q;
    cin >> n >> m >> q;
    int a[q];
    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> range{{1, 1}, {m, m + 1}, {n + 1, n + 1}};
    int ans = 1;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        bool inrange = false;
        for (int j = 0; j < sz(range); j++) {
            if (range[j].first <= x && x <= range[j].second) {
                for (int k = j + 1; k < sz(range); k++) {
                    range[k].first--;
                }
                for (int k = 0; k < j; k++) {
                    range[k].second++;
                }
                inrange = true;
            }
        }
        if (inrange == false) {
            int j = lower_bound(all(range), pair<int, int>{x, x}) - range.begin();
            if (j < sz(range)) {
                assert(x < range[j].second);
                for (int k = j; k < sz(range); k++) {
                    range[k].first--;
                }
                for (int k = 0; k < j; k++) {
                    range[k].second++;
                }
            }
        }


        cout << ans << ' ';
    }
    cout << endl;
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
