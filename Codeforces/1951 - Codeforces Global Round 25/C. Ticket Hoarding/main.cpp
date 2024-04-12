// ﷽
// https://codeforces.com/contest/1951/problem/C

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    rpq<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push({a[i], i});
    }

    vector<int> cnt(n);
    while (k) {
        auto [x, i] = pq.top();
        pq.pop();
        cnt[i] = min(k, m);
        k -= cnt[i];
    }

    debug(cnt);
    int ans = 0;
    for (int i = 0, prev = 0; i < n; i++) {
        debug(i, prev);
        ans += cnt[i] * a[i] + prev * cnt[i];
        prev += cnt[i];
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
