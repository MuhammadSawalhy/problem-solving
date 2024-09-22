// ﷽
// https://atcoder.jp/contests/abc365/tasks/abc365_g

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

const int N = 2e5 + 5;

vector<int> t[N];
vector<int> queries[N];
vector<pii> qus;
set<pii> ex;
map<pii, int> ans;

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int tt, p;
        cin >> tt >> p;
        p--;
        t[p].push_back(tt);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        if (t[u].size() < t[v].size()) swap(u, v);
        if (t[u].size() == t[v].size() && u > v) swap(u, v);
        qus.emplace_back(u, v);
        if (ex.count({u, v}) == 0)
            queries[u].emplace_back(v);
        ex.insert({u, v});
    }

    debug_itr(t, n);
    debug_itr(queries, n);

    vector<int> order(n);
    iota(all(order), 0);

    sort(all(order), [&](int l, int r) {
        return t[l].size() > t[r].size();
    });

    for (int i = 0; i < n; i++) {
        int ii = order[i];
        if (queries[ii].size() == 0) continue;
        set<int> s, e;

        for (int k = 0; k < sz(t[ii]); k += 2) {
            s.insert(t[ii][k]);
            e.insert(t[ii][k + 1]);
        }

        for (auto jj: queries[ii]) {
            int val = 0;
            for (int k = 0; k < sz(t[jj]); k += 2) {
                int l = t[jj][k], r = t[jj][k + 1];
                auto its = s.lower_bound(l);
                auto ite = e.lower_bound(l);
                if (ite == e.end()) continue;
                if (its != s.end()) {
                    if (*its < *ite) {
                        maxit(l, *its);
                    }
                }
                minit(r, *ite);
                if (l <= r)
                    val += r - l;
            }
            ans[{ii, jj}] = val;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[qus[i]] << endl;
    }

    return 0;
}
