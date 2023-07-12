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

const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
#ifdef DEBUG
    freopen("main_input0.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c, a--, b--;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    const ll inf = 1e18;
    vector<ll> price(n, inf), cnt(n), cntmin(n), cntmax(n);
    cnt[0] = 1;
    price[0] = 0;
    pq.push({0, 0});

    while (pq.size()) {
        auto [d, i] = pq.top();
        pq.pop();
        if (d > price[i]) continue;

        for (auto [j, c]: adj[i]) {
            if (d + c < price[j]) {
                price[j] = d + c;
                cnt[j] = cnt[i];
                cntmin[j] = cntmin[i] + 1;
                cntmax[j] = cntmax[i] + 1;
                pq.push({price[j], j});
            } else if (d + c == price[j]) {
                cnt[j] += cnt[i];
                cnt[j] %= (int)1e9 + 7;
                cntmin[j] = min(cntmin[j], cntmin[i] + 1);
                cntmax[j] = max(cntmax[j], cntmax[i] + 1);
            }
        }
    }

    cout << price[n - 1] << ' ' << cnt[n - 1] << ' ' << cntmin[n - 1] << ' ' << cntmax[n - 1] << endl;

    return 0;
}
