// ﷽
#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

struct Gen {
    static vector<int> perm(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = i;
        shuffle(a.begin(), a.end());
        return a;
    }

    static vector<int> tree_parents(int n) {
        vector<int> p(n - 1);
        auto a = perm(n);
        // a[0] = 1, is the root
        shuffle(a.begin() + 1, a.end());
        for (int32_t i = 1; i < n; i++)
            p[i - 1] = a[rnd.next(0, i - 1)] + 1;
        return p;
    }

    static vector<pair<int, int>> tree_edges(int n) {
        auto a = perm(n);
        vector<pair<int, int>> edges;
        for (int32_t i = 1; i < n; i++)
            edges.push_back({a[i] + 1, a[rnd.next(0, i - 1)] + 1});
        return edges;
    }

    static vector<vector<int>> tree_adj(int n) {
        vector<vector<int>> adj(n);
        for (auto [u, v]: tree_edges(n)) {
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    static string str(int n) {
        string s;
        for (int i = 0; i < n; i++)
            s += rnd.next('a', 'z');
        return s;
    }
};

using vvi = vector<vector<int>>;
struct SCC {
    int N, ID = 0, COMP = 0;
    const vvi &adj;
    vector<int> id, comp, st;

    SCC(const vvi &adj) : adj(adj), N(adj.size()) {
        id = comp = vector<int>(N, -1);
        go();
    }

    void go() {
        for (int i = 0; i < N; i++)
            if (id[i] == -1) dfs(i);
    }

    int dfs(int i) {
        int low = id[i] = ID++;
        st.push_back(i);
        for (int j: adj[i])
            if (comp[j] == -1)
                low = min(low, id[j] == -1 ? dfs(j) : id[j]);
        if (low == id[i]) {
            for (int j = -1; j != i;)
                comp[j = st.back()] = COMP, st.pop_back();
            COMP++;
        }
        return low;
    }

    vvi dag(bool reverse = false) {
        vvi newadj(COMP);
        for (int i = 0; i < N; i++)
            for (auto j: adj[i])
                if (comp[i] != comp[j]) {
                    if (reverse) newadj[comp[j]].push_back(comp[i]);
                    else newadj[comp[i]].push_back(comp[j]);
                }
        return newadj;
    }
};

void interact() {
    // cout to the solution and cin from it, interact and enjoy
    int n = rnd.next(1, 10);
    int x = rnd.next(1, 2 * n);
    set<pair<int, int>> edges;

    while (x--) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        if (u != v) edges.insert({u, v});
    }

    cout << n << ' ' << edges.size() << endl;

    for (int i = 0; i < n; i++) {
        cout << rnd.next(1, 10) << ' ';
    }
    cout << endl;

    for (auto e: edges) {
        cout << e.first << ' ' << e.second << endl;
    }

    int cost, cnt;
    cin >> cost >> cnt;

    for (int i = 0; i < cnt; i++) {
        int u, v;
        cin >> u >> v;
        edges.insert({u, v});
    }

    vvi adj(n);

    for (auto [u, v]: edges) {
        u--, v--;
        adj[u].push_back(v);
    }

    SCC scc(adj);

    assert(scc.COMP == 1);
}

int32_t main(int32_t argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int t = 1;
    while (t--) {
        interact();
    }

    return 0;
}
