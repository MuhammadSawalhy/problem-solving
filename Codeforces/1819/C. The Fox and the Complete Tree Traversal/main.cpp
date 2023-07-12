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

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 2e5 + 5;
vector<int> adj[N];
int mx_depth = 0, diam_end[2];

vector<int> diam;

void dfs1(int i, int p, int d) {
    if (d > mx_depth) {
        mx_depth = d;
        diam_end[0] = i;
    }

    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs1(j, i, d + 1);
    }
}

void dfs2(int i, int p, int d) {
    if (d > mx_depth) {
        mx_depth = d;
        diam_end[1] = i;
    }

    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs2(j, i, d + 1);
    }
}

bool ok = false;
bool on_diam[N];
void dfs3(int i, int p) {
    diam.push_back(i);
    on_diam[i] = true;
    if (i == diam_end[1]) return ok = true, void();
    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs3(j, i);
        if (ok) return;
    }
    on_diam[i] = false;
    diam.pop_back();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    // get the diameter
    // process node of the diameter

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    mx_depth = 0;
    dfs1(0, 0, 0);
    mx_depth = 0;
    dfs2(diam_end[0], diam_end[0], 0);
    dfs3(diam_end[0], diam_end[0]);

    vector<int> ans;

    // 0: node
    // 1: children
    int mode = 0;

    for (int i: diam) {
        if (mode) {
            for (int j: adj[i]) {
                if (!on_diam[j])
                    ans.push_back(j);
            }
        } else {
            ans.push_back(i);
        }
        mode ^= 1;
    }

    reverse(all(diam));
    for (int i: diam) {
        if (mode) {
            for (int j: adj[i]) {
                if (!on_diam[j])
                    ans.push_back(j);
            }
        } else {
            ans.push_back(i);
        }
        mode ^= 1;
    }

    if (ans.size() == n) {
        cout << "Yes\n";
        for (auto i: ans)
            cout << i + 1 << " ";
    } else {
        cout << "No\n";
    }

    return 0;
}
