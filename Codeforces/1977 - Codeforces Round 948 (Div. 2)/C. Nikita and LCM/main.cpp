// ﷽
// https://codeforces.com/contest/1977/problem/C

#include <algorithm>
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
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> A;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A.insert(a[i]);
    }

    map<ll, ll> lc;
    lc[1] = 0;

    int mx = *max_element(all(A));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto newlc = lc;
        debug(lc);
        for (auto [x, cnt]: lc) {
            int cur = lcm(x, a[i]);
            maxit(newlc[cur], cnt + 1);
            if (!A.count(cur)) {
                maxit(ans, newlc[cur]);
            }
        }

        lc = newlc;
        maxit(lc[a[i]], 1ll);

        if (prev(lc.end())->first > mx) {
            ans = n;
            break;
        }
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
