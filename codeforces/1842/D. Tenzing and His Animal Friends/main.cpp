// ﷽
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> con;
    vector<pair<bitset<100>, int>> ans;
    ll T = 0;

    for (int i = 0, u, v, y; i < m; i++) {
        cin >> u >> v >> y, u--, v--;
        con.push_back({u, v, y});
    }

    const ll inf = 1e18;
    int round = 0;
    bitset<100> S;
    S[0] = 1;
    // 0. add 1 to the set

    // is max of round = n?
    while (++round <= n * n) {
        // go in rounds

        // 1. calculate t (min constraint applicable)
        // 1.5. if can't find one, INF

        ll t = inf;

        for (int i = 0; i < m; i++) {
            auto [u, v, y] = con[i];
            debug(y);
            if (S[u] != S[v]) t = min(t, y);
        }

        if (t == inf) {
            cout << "inf" << endl;
            return;
        }

        // 2. register new round

        ans.push_back({S, t});
        T += t;

        // 3. update the constraints' y and add to the set whose y = 0
        // 3.5. if a y = 0 with the friend n, then break

        bitset<100> news = S;
        for (int i = 0; i < m; i++) {
            auto &[u, v, y] = con[i];
            if (S[u] != S[v]) {
                y -= t;
                if (y == 0 && (u == n - 1 || v == n - 1)) {
                    goto line;
                }
                if (y == 0) {
                    news[u] = news[v] = 1;
                }
            }
        }

        S = news;
    }

line:;

    // DOES THIS GREEDY ALGORITHM GUARANTEE THE MAX "T"? **Seems like YES**

    cout << T << ' ' << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        string s;
        for (int j = 0; j < n; j++) {
            if (ans[i].first[j]) s += '1';
            else s += '0';
        }
        cout << s << ' ' << ans[i].second;
        if (i + 1 < ans.size()) cout << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
