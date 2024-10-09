// ﷽
// https://cses.fi/problemset/task/1147

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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    vi mx(m, -1);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        debug(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') mx[j] = i;
        }
        debug(mx);

        vector<pii> st { {1e9, -1} };

        for (int j = 0; j < m; j++) {
            debug(j);
            while (st.size() && st.back().first < mx[j]) {
                // update ans
                int val = (j - st.end()[-2].second - 1) * (i - st.back().first);
                debug(st.back(), val);
                maxit(ans, val);
                st.pop_back();
            }

            st.push_back({mx[j], j});
        }
        while (st.size() > 1) {
            // update ans
            int val = (m - st.end()[-2].second - 1) * (i - st.back().first);
            debug(st.back(), val);
            maxit(ans, val);
            st.pop_back();
        }
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
