// ﷽
// https://codeforces.com/contest/2002/problem/D1

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
    int n, q;
    cin >> n >> q;

    vector<int> par(n + 1), pos(n + 1), perm(n + 1);
    vector<bool> isrule1(n + 1), isrule2(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> par[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> perm[i];
        pos[perm[i]] = i;
    }

    set<int> c[n + 1];

    int rule1 = 0, rule2 = 0;

    auto rem = [&](int i) {
        int p = i / 2;
        while (p) {
            c[p].erase(pos[i]);
            p /= 2;
        }
    };

    auto ins = [&](int i) {
        int p = i / 2;
        while (p) {
            c[p].insert(pos[i]);
            p /= 2;
        }
    };

    for (int i = 1; i <= n; i++) {
        ins(i);
    }

    auto update_rules = [&](int i) {
        if (!c[i].size()) return;
        int mn = *c[i].begin(), mx = *c[i].rbegin();
        if (pos[i] != mn - 1) {
            debug("i", i);
            rule1 -= isrule1[i];
            isrule1[i] = true;
            rule1 += isrule1[i];
        } else {
            rule1 -= isrule1[i];
            isrule1[i] = false;
            rule1 += isrule1[i];
        }

        if (mx - mn + 1 != c[i].size()) {
            rule2 -= isrule2[i];
            isrule2[i] = true;
            rule2 += isrule2[i];
        } else {
            rule2 -= isrule2[i];
            isrule2[i] = false;
            rule2 += isrule2[i];
        }
    };

    auto updateall = [&](int i) {
        while (i) {
            assert(__popcount(c[i].size() + 2) <= 1);
            update_rules(i);
            i /= 2;
        }
    };

    for (int i = 1; i <= n; i++) {
        update_rules(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        bool isp = false;

        rem(perm[x]);
        rem(perm[y]);

        swap(pos[perm[x]], pos[perm[y]]);
        swap(perm[x], perm[y]);
        debug(perm);

        ins(perm[x]);
        ins(perm[y]);

        updateall(perm[x]);
        updateall(perm[y]);

        assert(rule1 >= 0 && rule2 >= 0);
        assert(rule1 <= n && rule2 <= n);
        cout << (rule1 + rule2 == 0 ? "YES" : "NO") << '\n';
    }
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
