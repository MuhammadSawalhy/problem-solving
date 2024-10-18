/*
Problem Name: Chess Tournament
Problem Link: https://cses.fi/problemset/task/1697
Author: Sachin Srivastava (mrsac7)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n + 1];
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) st.insert({a[i], i});
    }
    vector<pair<int, int>> ans;
    while (st.size() >= 2) {
        auto [x1, i1] = *st.begin();
        st.erase({x1, i1});
        vector<pair<int, int>> s;
        while (x1 > 0 && st.size()) {
            auto [x2, i2] = *st.rbegin();
            st.erase({x2, i2});
            ans.push_back({i1, i2});
            x1--, x2--;
            if (x2) s.push_back({x2, i2});
        }
        for (auto &p: s) st.insert(p);
    }
    if (st.size() == 0) {
        cout << ans.size() << endl;
        for (auto [i, j]: ans) cout << i << ' ' << j << endl;
    } else cout << "IMPOSSIBLE";
}
