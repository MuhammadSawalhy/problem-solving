#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> ans;

    ans.push_back({0, 0, n - 1});
    for (int i = 1; i < n; i++) {
        ans.push_back({i, 0, i - 1});
        ans.push_back({i, i, n - 1});
    }

    cout << ans.size() << endl;
    for (auto [i, j, k]: ans) {
        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
