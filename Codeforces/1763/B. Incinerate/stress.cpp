// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
    ll n, k;
    cin >> n >> k;
    int h[n], p[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> p[i];

    int order[n];
    iota(order, order + n, 0);
    sort(order, order + n, [&](int l, int r) {
        if (p[l] == p[r])
            return h[l] < h[r];
        return p[l] < p[r];
    });

    ll loss = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && loss < h[order[i]]) {
            loss += k;
            k -= p[order[i]];
        }
        if (h[order[i]] > loss) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
