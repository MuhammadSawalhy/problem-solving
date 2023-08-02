// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define int    long long
#define ll     long long
#define all(v) v.begin(), v.end()

const int inf = 1e9;
const int N = 2e5 + 5;
map<int, int> fr;
map<pair<int, int>, bool> isq, isgood;
int branches[N];

struct Node {
    int idx;
    int number = -inf;
    int cycle_node;
    int cycle = -1;
    int branch;
    bool on_cycle = false;

    int distance(const Node &to, Node nodes[]) {
        if (cycle != to.cycle) return inf; // same connected component (undirected)
        if (on_cycle && to.on_cycle) {     // both are on cycle
            int x = to.number - number;
            if (x < 0) return fr[cycle] + x;
            return x;
        }

        if (on_cycle != to.on_cycle) {
            if (on_cycle) return inf;
            return nodes[cycle_node].distance(to, nodes) + nodes[cycle_node].number - number;
        }

        // both should be on the same branch
        if (branch != to.branch || number > to.number || !isgood[{idx, to.idx}])
            return inf;
        return to.number - number;
    }

    void print() {
        cout << "{" << endl;
#define dbg(x) cout << "\t" << #x << ": " << x << endl;
        dbg(number);
        dbg(on_cycle);
        dbg(cycle);
        dbg(cycle_node);
#undef dbg
        cout << "}" << endl;
    }
};

Node nodes[N];

struct SCC {
    int N, ID = 0, COMP = 0;
    vector<vector<int>> adj;
    vector<int> id, comp, st;

    SCC(const vector<vector<int>> &adj) : adj(adj), N(adj.size()) {
        id.resize(N), comp = vector<int>(N, -1);
        go();
    }

    void go() {
        for (int i = 0; i < N; i++)
            if (!id[i]) dfs(i);
    }

    int dfs(int i) {
        int low = id[i] = ++ID;
        st.push_back(i);
        for (int j: adj[i])
            if (comp[j] == -1)
                // id[j] != 0 -> in stack, don't dfs
                low = min(low, id[j] ?: dfs(j));
        if (low == id[i]) {
            COMP++;
            for (int j = -1; j != i;)
                comp[j = st.back()] = COMP, st.pop_back();
        }
        return low;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n), radj(n);
    for (int i = 0, j; i < n; i++) {
        nodes[i].idx = i;
        cin >> j, j--;
        adj[i].push_back(j);
        radj[j].push_back(i);
        if (i == j) {
            nodes[i].on_cycle = true;
        }
    }

    vector<vector<pair<int, int>>> queries(n);
    for (int _ = 0; _ < q; _++) {
        int i, j;
        cin >> i >> j, i--, j--;
        queries[i].emplace_back(j, _);
    }


    SCC scc(adj);
    for (int i = 0; i < n; i++) {
        fr[scc.comp[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (fr[scc.comp[i]] > 1) {
            nodes[i].on_cycle = true;
        }
    }

    function<void(int, int)> dfs1 = [&](int i, int d) {
        assert(nodes[i].on_cycle);
        nodes[i].number = d;
        nodes[i].cycle = scc.comp[i];
        for (auto j: adj[i]) {
            if (nodes[j].number == -inf)
                dfs1(j, d + 1);
        }
    };

    vector<bool> onstack(n);
    function<void(int, int, int, int, int)> dfs2 = [&](int cycle, int branch, int cycle_node, int i, int d) {
        assert(i == cycle_node || nodes[i].on_cycle == false);
        onstack[i] = true;
        if (i != cycle_node) {
            nodes[i].cycle_node = cycle_node;
            nodes[i].cycle = cycle;
            nodes[i].number = d;
            nodes[i].branch = branch;
        }
        for (auto j: radj[i]) {
            if (nodes[j].number != -inf) continue;
            if (i == cycle_node) {
                dfs2(cycle, branches[cycle]++, cycle_node, j, d - 1);
            } else {
                dfs2(cycle, branch, cycle_node, j, d - 1);
            }
        }
        for (auto [j, _]: queries[i]) {
            if (onstack[i] && onstack[j]) {
                isgood[{i, j}] = true;
            }
        }
        onstack[i] = false;
    };

    for (int i = 0; i < n; i++) {
        if (nodes[i].on_cycle && nodes[i].number == -inf) dfs1(i, 0);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i].on_cycle) dfs2(nodes[i].cycle, 0, i, i, nodes[i].number);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << endl;
    //     nodes[i].print();
    // }

    vector<int> ans(q);
    for (int i = 0; i < n; i++)
        for (auto [j, k]: queries[i]) {
            Node a = nodes[i], b = nodes[j];
            int c = a.distance(b, nodes);
            ans[k] =  (c > inf / 2 ? -1 : c);
        }

    for (auto i : ans)
        cout << i << '\n';

    return 0;
}
