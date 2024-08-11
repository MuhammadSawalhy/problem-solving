// ﷽
// https://codeforces.com/contest/2002/problem/D2

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    debug("--------------");

    vector<int> par(n + 1), pos(n + 1), perm(n + 1), size(n + 1);
    vector<bool> parafter(n + 1), parfar(n + 1);
    vector<int> adj[n + 1];
    ordered_set<int> chpos[n + 1];
    ordered_set<pii> chszpos[n + 1];

    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> perm[i];
        pos[perm[i]] = i;
    }

    int tparafter = 0, tparfar = 0;

    function<void(int)> dfs = [&](int i) -> void {
        size[i] = 1;
        for (auto j: adj[i]) {
            dfs(j);
            size[i] += size[j];
            chpos[i].insert(pos[j]);
            chszpos[i].insert({pos[j] + size[j] - 1, j});
        }
    };

    dfs(1);

    auto update_rules = [&](int i, int delta) {
        debug("update", i, delta);
        // update i (parent) ch[i] (child)

        // count (pos[i] > pos[ch[i]])
        tparafter += delta * (chpos[i].order_of_key(pos[i]));
        debug(tparafter);

        // pos[ch[i]] + size[ch[i]] - 1 > pos[i] + size[i] - 1
        tparfar += delta * (chszpos[i].size() - chszpos[i].order_of_key({pos[i] + size[i], 0}));
        debug(tparfar);

        if (i == 1) return;

        if (delta == -1) {
            chpos[par[i]].erase(pos[i]);
            chszpos[par[i]].erase({pos[i] + size[i] - 1, i});
        } else {
            chpos[par[i]].insert(pos[i]);
            chszpos[par[i]].insert({pos[i] + size[i] - 1, i});
        }

        // update par[i] (parent) i (child)

        if (pos[par[i]] > pos[i]) {
            tparafter += delta;
            debug(tparafter);
        }

        if (pos[i] + size[i] - 1 > pos[par[i]] + size[par[i]] - 1) {
            tparfar += delta;
            debug(tparfar);
        }
    };

    for (int i = 1; i <= n; i++) {
        update_rules(i, +1);
    }

    tparafter /= 2;
    tparfar /= 2;

    debug(perm);
    debug(tparafter, tparfar);
    debug();
    while (q--) {
        int x, y;
        cin >> x >> y;

        if (par[perm[y]] == perm[x]) swap(x, y); // y is parent

        update_rules(perm[x], -1);
        update_rules(perm[y], -1); // parent

        swap(pos[perm[x]], pos[perm[y]]);
        swap(perm[x], perm[y]);

        update_rules(perm[x], +1); // parent
        update_rules(perm[y], +1);

        debug(x, y);
        debug(perm);
        debug(tparafter, tparfar);
        debug();

        assert(tparafter >= 0 && tparfar >= 0);
        assert(tparafter <= n && tparfar <= n);
        cout << (tparafter + tparfar == 0 ? "YES" : "NO") << '\n';
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
