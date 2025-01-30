#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


const int N = 2e5 + 5;
vector<pair<int, int>> a(N);
vector<int> adj[N];

map<int, pair<int, int>> val;

pair<int, int> solve(int i, int p) {
    if (val.count(i)) return val[i];
    int ans = 0, up = 0;

    for (auto j: adj[i]) {
        if (j == p) continue;
        auto [a, b] = solve(j, i);
        up += b;
    }

    vector<int> v;
    for (auto j: adj[i]) {
        if (j == p) continue;
        auto [a, b] = solve(j, i);
        v.push_back(a + up - b);
    }

    a[i].first += up;
    a[i].second += up;
    if (v.size()) {
        debug(i, a[i].second);
        sort(v.begin(), v.end());
        debug(v);
        if (a[i].second >= v.back()) {
            ans = max(a[i].first, v.back());
            return val[i] = {ans, up};
        }
        int l = -1, r = 1e18;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int my = a[i].second + mid;
            auto vv = v;
            int cur = mid;
            bool ok = true;
            for (int i = 0; i < vv.size(); i++) {
                vv[i] += mid;
                if (vv[i] > my) {
                    int d = vv[i] - my;
                    cur -= d;
                    vv[i] -= d;
                    if (cur < 0) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                r = mid;
            } else {
                l = mid;
            }
        }

        debug(r);
        ans = a[i].second + r;
        up += r;
    } else {
        ans = a[i].first;
        up = 0;
    }

    return val[i] = {ans, up};
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << solve(0, 0).first << endl;
    for (int i = 0; i < n; i++) adj[i].clear();
    debug(val);
    val.clear();
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
    return 0;
}
