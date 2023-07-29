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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    vector<int> pos, neg;
    int mn = 1e18, mx = -1e18;
    vector<int> a(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0)
            pos.push_back(i + 1);
        if (a[i] < 0)
            neg.push_back(i + 1);
        mn = min(a[i], mn);
        mx = max(a[i], mx);
    }

    bool P = pos.size();
    if (min(pos.size(), neg.size()) < 8 && pos.size() && neg.size()) {
        if (neg.size() < pos.size()) {
            for (int j = 0; j < 5; j++) {
                ans.push_back({pos.front(), pos.front()});
            }
            for (auto j: neg) {
                ans.push_back({j, pos.front()});
            }
        } else {
            P = false;
            for (int j = 0; j < 5; j++) {
                ans.push_back({neg.front(), neg.front()});
            }
            for (auto j: pos) {
                ans.push_back({j, neg.front()});
            }
        }
    } else if (pos.size() && neg.size()) {
        if (abs(mn) > abs(mx)) {
            // make all -ve
            P = false;
            int i = min_element(all(a)) - a.begin();
            for (auto j: pos) {
                ans.push_back({j, i + 1});
            }
        } else {
            // make all +ve
            int i = max_element(all(a)) - a.begin();
            for (auto j: neg) {
                ans.push_back({j, i + 1});
            }
        }
    }

    if (P) {
        for (int i = 2; i <= n; i++)
            ans.push_back({i, i - 1});
    } else {
        for (int i = n - 1; i > 0; i--)
            ans.push_back({i, i + 1});
    }

    assert(ans.size() <= 31);
    cout << ans.size() << endl;
    for (auto [i, j]: ans) {
        cout << i << ' ' << j << endl;
    }
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
