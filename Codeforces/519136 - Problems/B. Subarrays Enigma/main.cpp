// ﷽
// https://codeforces.com/group/diAwUqxD2g/contest/519136/problem/B

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    return;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b;
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (b.empty()) {
            b.push_back({a[i], 1});
            ps[b.size()] = 1;
            ps[b.size()] += ps[b.size() - 1];
        } else {
            if (b.back().first == a[i]) {
                b.back().second++;
                ps[b.size()] += 1;
            } else {
                b.push_back({a[i], 1});
                ps[b.size()] = 1;
                ps[b.size()] += ps[b.size() - 1];
            }
        }
    }

    int prev[10];
    memset(prev, -1, sizeof prev);
    debug(ps);

    int mx = -1;
    int ans = 0;
    for (int i = 0; i < sz(b); i++) {
        maxit(mx, prev[b[i].first]);
        debug(i, b[i], mx);
        prev[b[i].first] = i;
        int x = b[i].second;
        int y = ps[i + 1] - ps[mx + 1] - x;
        // y + 1 + y + 2 + ... + y + x;
        ans += (x + y) * (x + y + 1) / 2 - (y) * (y + 1) / 2;
        debug(ans);
    }

    cout << ans << endl;

    return 0;
}
