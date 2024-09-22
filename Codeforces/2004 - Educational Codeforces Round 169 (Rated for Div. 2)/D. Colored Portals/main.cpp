// ﷽
// https://codeforces.com/contest/2004/problem/D

#include <algorithm>
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

vector<pii> nxt[4][4];

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pii> t(n);
    vector<char> types{'B', 'G', 'R', 'Y'};

    vector<int> nodes[4][4];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = find(all(types), s[0]) - types.begin();
        int y = find(all(types), s[1]) - types.begin();
        if (x > y) swap(x, y);
        t[i] = {x, y};
        nodes[x][y].push_back(i);
    }

    debug(nodes[0][2]);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y, x--, y--;

        if (x > y) swap(x, y);
        int ans = 1e18;

        auto [a, b] = t[x];
        auto [aa, bb] = t[y];

        set<int> s{a, b, aa, bb};
        if (sz(s) < 4) {
            cout << abs(x - y) << endl;
            continue;
        }

        for (int k = 0; k < 4; k++) {
            for (int l = k + 1; l < 4; l++) {
                set<int> s1{a, b, l, k};
                set<int> s2{l, k, aa, bb};
                if (sz(s1) == 3 && sz(s2) == 3) {
                    auto it = lower_bound(all(nodes[k][l]), x);
                    if (it != nodes[k][l].end()) {
                        minit(ans, abs(*it - x) + abs(*it - y));
                    }
                    if (it != nodes[k][l].begin()) {
                        it--;
                        minit(ans, abs(*it - x) + abs(*it - y));
                    }
                }
            }
        }


        if (ans == 1e18) ans = -1;
        cout << ans << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = k + 1; l < 4; l++) {
                    if (k == i && l == j) continue;
                    if (l == i || l == j || k == i || k == j)
                        nxt[i][j].push_back({k, l});
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            debug(i, j, nxt[i][j]);
        }
    }

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
