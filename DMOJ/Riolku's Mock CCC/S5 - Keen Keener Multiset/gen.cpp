// ﷽
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

struct Gen {
    // rnd.next(n) -> integer [0, n)
    // rnd.next(l, r) -> integer [l, r]
    // rnd.perm() -> permutation
    // rnd.partition -> get `n` numbers with sum `s`, useful for multitest

    // ------------------------------------------------

    /** one-based */
    static vi tree_parents(int n, int root = 1) {
        vector<int> p(n - 1);
        auto a = rnd.perm(n);
        for (int i = 0; i < n; i++) a[i]++;
        for (int i = 1; i < n; i++)
            if (a[i] == root) swap(a[0], a[i]);
        for (int i = 0; i < n - 1; i++) p[i] = a[rnd.next(0ll, i)];
        return p;
    }

    /** one-based */
    static vector<pii> tree_edges(int n) {
        auto a = rnd.perm(n);
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++) a[i]++;
        for (int i = 1; i < n; i++)
            edges.emplace_back(a[i], a[rnd.next(0ll, i - 1)]);
        return edges;
    }

    static vector<pii> star_tree(int n, int root = 1) {
        vector<pii> edges;
        for (int i = 1; i <= n; i++)
            if (i != root) edges.emplace_back(root, i);
        return edges;
    }

    static vector<pii> line_tree(int n) {
        auto a = rnd.perm(n);
        vector<pii> edges;
        for (int i = 1; i < n; i++)
            edges.emplace_back(a[i] + 1, a[i - 1] + 1);
        return edges;
    }

    /** zero-based */
    static vvi edges_to_adj(int n, const vector<pii> &edges) {
        vector<vector<int>> adj(n);
        for (auto [u, v]: edges) {
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    // ------------------------------------------------

    static string str(int n, int uppercase = 0, char l = 'a', char r = 'z') {
        string s;
        assert(n >= 0 && n <= 1e6);
        for (int i = 0; i < n; i++) {
            char c = rnd.next(l, r);
            if (uppercase == 0) s += c;
            if (uppercase == 2) s += toupper(c);
            if (uppercase == 1) s += rnd.next(0, 1) == 0 ? c : toupper(c);
        }
        return s;
    }
};

void gen() {
    int n = 2e5, q = 2e5;
    int32_t mx = 1 << 18;

    println(n, q);

    for (int i = 0; i < n; i++) cout << rnd.next(0, mx) << " \n"[i == n - 1];

    while (q--) {
        int type = rnd.next(1, 3);
        if (type == 1) {
            int x = rnd.next(0, mx);
            println(type, x);
        } else if (type == 2) {
            int l = rnd.next(0, mx), r = rnd.next((int32_t) l, mx), up = rnd.next(0, mx);
            println(type, l, r, up);
        } else {
            int l = rnd.next(0, mx), r = rnd.next((int32_t) l, mx);
            println(type, l, r);
        }
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    registerGen(argc, argv, 1);
    gen();
    return 0;
}
