// ﷽
// https://codeforces.com/contest/2002/problem/E

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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    debug(a);

    vector<pii> st;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto [fr, x] = a[i];
        int time = 0;
        while (st.size()) {
            if (st.back().first <= time) {
                st.pop_back();
                continue;
            }

            if (st.back().second == x) {
                assert(st.back().first > time);
                assert(fr >= time);
                fr = fr + st.back().first - time;
                st.pop_back();
                continue;
            }

            if (st.back().first <= fr) {
                // time will increase, pop the stack
                time = st.back().first;
                st.pop_back();
            } else {
                st.push_back({fr, x});
                break;
            }
        }

        if (st.size() == 0) {
            st.push_back({fr, x}); // TODO
        }

        if (st.size() == 1) {
            ans[i] = st.back().first;
        }

        debug(st);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) maxit(ans[i], ans[i - 1]);
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
