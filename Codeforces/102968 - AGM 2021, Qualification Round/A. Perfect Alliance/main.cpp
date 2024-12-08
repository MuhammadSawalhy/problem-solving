#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

const int N = 4010, INF = 1e9;

int n, m, cost[N], comp_cost[N], comp_node[N];
vector<int> adj[N], reverseGraph[N];
int indeg[N], outdeg[N];
bool visited[N];

struct SCC {
    int n, ID = 0, COMP = 0;
    vector<int> id, comp, st;

    SCC(int n) : n(n) {
        id = comp = vector<int>(n, -1);
        go();
    }

    void go() {
        for (int i = 0; i < n; i++)
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

    vector<vector<int>> dag(bool reverse = false) {
        vector<vector<int>> newadj(COMP);
        for (int i = 0; i < n; i++)
            for (auto j: adj[i])
                if (comp[i] != comp[j]) {
                    if (reverse) newadj[comp[j]].push_back(comp[i]);
                    else newadj[comp[i]].push_back(comp[j]);
                }
        return newadj;
    }
};

bool done[N], used[N];
vector<pair<int, int>> pairs;
vector<pair<int, int>> edges;
int pivot = 0, minval = INF;
vector<vector<int>> dag, rdag;

void dfs(int i, int s) {
    if (done[i]) return;
    done[i] = true;
    if (outdeg[i] == 0 && !used[s]) {
        pairs.push_back({s, i});
        used[s] = used[i] = true;
    }
    for (auto j: dag[i]) dfs(j, s);
}

void join() {
    int n = dag.size();

    debug(pivot);
    int cur = pivot;
    done[pivot] = true;
    while (rdag[cur].size()) {
        cur = rdag[cur].front();
        done[cur] = true;
    }
    int start = cur;
    cur = pivot;
    while (dag[cur].size()) {
        cur = dag[cur][0];
        done[cur] = true;
    }
    int end = cur;
    debug(start, end);
    pairs.push_back({start, end});
    used[start] = used[end] = true;

    for (int i = 0; i < n; i++) {
        if (!done[i] && indeg[i] == 0)
            dfs(i, i);
    }
    int sz = pairs.size();
    debug(pairs);
    for (int i = 0; i < sz - 1; i++) edges.push_back({pairs[i].second, pairs[i + 1].first});
    edges.push_back({pairs[sz - 1].second, pairs[0].first});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
    }

    SCC scc(n);
    int cnt = scc.COMP;
    dag = scc.dag();
    rdag = scc.dag(true);

    debug(dag);
    for (int i = 0; i < cnt; i++)
        for (auto j: dag[i]) cerr << i << ' ' << j << endl;

    for (int i = 0; i < cnt; i++) {
        comp_cost[i] = INF;
        for (auto j: dag[i]) {
            outdeg[i]++;
            indeg[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int c = scc.comp[i];
        if (cost[i] < comp_cost[c]) {
            comp_cost[c] = cost[i];
            comp_node[c] = i;
        }
    }

    for (int i = 0; i < cnt; ++i) {
        if (comp_cost[i] < minval) {
            minval = comp_cost[i];
            pivot = i;
        }
    }

    long long totalCost = 0;

    vector<int> sources, sinks;
    for (int i = 0; i < cnt; ++i) {
        if (indeg[i] == 0) sources.push_back(i), totalCost += comp_cost[i];
        if (outdeg[i] == 0) sinks.push_back(i), totalCost += comp_cost[i];
    }

    int sc = sources.size(), sk = sinks.size();
    totalCost += minval * abs(sc - sk);

    join();

    sources.erase(remove_if(sources.begin(), sources.end(), [&](int i) {
                      return used[i];
                  }),
                  sources.end());

    sinks.erase(remove_if(sinks.begin(), sinks.end(), [&](int i) {
                    return used[i];
                }),
                sinks.end());

    debug(sources);
    debug(sinks);
    sc = sources.size(), sk = sinks.size();
    for (int i = 0; i < min(sc, sk); ++i) edges.emplace_back(sinks[i], sources[i]);
    for (int i = sk; i < sc; ++i) edges.emplace_back(pivot, sources[i]);
    for (int i = sc; i < sk; ++i) edges.emplace_back(sinks[i], pivot);

    for (const auto &[u, v]: edges)
        cerr << u << ' ' << v << endl;
    cout << totalCost << '\n'
         << edges.size() << '\n';
    for (const auto &[u, v]: edges)
        cout << comp_node[u] + 1 << " " << comp_node[v] + 1 << '\n';
    cout.flush();

    return 0;
}
