// ﷽
// 11 جُمادى الآخرة 1444
// Jan 03, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int m;
    cin >> m;
    map<int, int> x;
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        x[y]++;
    }

    vector<pair<int, bool>> st;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            cout << "NO" << endl;
            return;
        }

        while (st.size() && st.back().first < b[i]) {
            if (st.back().second) {
                --x[st.back().first];
                if (x[st.back().first] < 0) {
                    cout << "NO" << endl;
                    return;
                }
            }
            st.pop_back();
        }

        bool needs = a[i] > b[i];

        if (st.size() && st.back().first == b[i]) {
            st.back().second |= needs;
        } else {
            st.push_back({b[i], needs});
        }
    }

    for (auto [l, needs]: st) {
        if (needs) {
            --x[l];
            if (x[l] < 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
