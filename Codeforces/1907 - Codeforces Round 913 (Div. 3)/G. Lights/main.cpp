// ﷽
// https://codeforces.com/contest/1907/problem/G

#include <bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> state(n);
    vector<int> a(n), deg(n), que;
    for (int i = 0; i < n; i++) {
        state[i] = s[i] == '1';
        cin >> a[i], a[i]--;
        deg[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            que.push_back(i);
        }
    }

    vector<int> ans;
    for (int i = 0; i < que.size(); i++) {
        int u = que[i];
        if (state[u]) {
            state[u] ^= 1;
            state[a[u]] ^= 1;
            ans.push_back(u);
        }
        deg[a[u]]--;
        if (deg[a[u]] == 0) {
            que.push_back(a[u]);
        }
    }

    debug(n);
    debug(que);
    debug(deg);

    // now fix cycles
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0 || vis[i]) continue;
        int u = i;
        vector<int> cycle, aCycle, bCycle;
        int ones = 0;
        while (!vis[u]) {
            ones += state[u];
            cycle.push_back(u);
            vis[u] = 1;
            u = a[u];
        }
        debug(cycle);

        int m = cycle.size();
        if (ones == 0) continue;
        if (ones & 1) {
            cout << "-1\n";
            return;
        }

        int last = -1;
        for (int i = 0; i < m; i++) {
            if (state[cycle[i]]) {
                if (last != -1) {
                    for (int x = last; x < i; x++)
                        aCycle.push_back(cycle[x]);
                    last = -1;
                } else {
                    last = i;
                }
            }
        }

        int first = -1;
        for (int i = 0; i < m; i++) {
            if (state[cycle[i]]) {
                if (first == -1) {
                    first = i;
                    continue;
                }
                if (last != -1) {
                    for (int x = last; x < i; x++)
                        bCycle.push_back(cycle[x]);
                    last = -1;
                } else {
                    last = i;
                }
            }
        }

        assert(first != -1 && last != -1);
        for (int i = 0; i < first; i++) bCycle.push_back(i);
        for (int i = last; i < m; i++) bCycle.push_back(i);

        if (bCycle.size() < aCycle.size()) {
            for (auto x: bCycle) ans.push_back(x);
        } else {
            for (auto x: aCycle) ans.push_back(x);
        }
    }

    cout << ans.size() << '\n';
    for (auto i: ans) cout << i + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
