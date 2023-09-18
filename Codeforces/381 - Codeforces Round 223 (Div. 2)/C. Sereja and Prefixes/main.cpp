// ﷽
// https://codeforces.com/problemset/problem/381/C
// Codeforces -> Codeforces Round 223 (Div. 2) -> C. Sereja and Prefixes

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int m;
    cin >> m;
    vector<array<int, 3>> ops;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            ops.push_back({t, x});
        } else {
            int l, c;
            cin >> l >> c;
            ops.push_back({t, l, c});
        }
    }

    int n;
    cin >> n;
    set<pair<int, int>> ind;
    vector<int> ans(n);
    map<int, int> dest;

    for (int i = 0, j; i < n; i++) {
        cin >> j;
        ind.insert({j, i});
    }

    for (int i = 0, sz = 0; i < m; i++) {
        if (ops[i][0] == 1) {
            sz += 1;
            dest[sz] = ops[i][1];
        } else {
            sz += ops[i][1] * ops[i][2];
        }
    }

    while (ind.size()) {
        int sz = 0, newsz;
        set<pair<int, int>> newind;
        auto j = ind.begin();

        for (int i = 0; i < m; i++) {
            int t = ops[i][0];
            int x = ops[i][1];
            int y = ops[i][2];
            newsz = sz;
            if (t == 1) {
                newsz += 1;
            } else {
                newsz += x * y;
            }

            while (j != ind.end() && j->first <= newsz) {
                // map the previos ind to the other one
                int newpos = j->first;
                if (t == 1) {
                    ans[j->second] = dest[newpos];
                } else {
                    newpos = (j->first - sz - 1) % x + 1;
                    newind.insert({newpos, j->second});
                }
                j++;
            }

            sz = newsz;
        }

        debug("", ind);
        debug(newind);
        ind = newind;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
