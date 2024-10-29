// ﷽
// https://csacademy.com/ieeextreme18/task/laser-defense/

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
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int L, n, m;
    cin >> L >> n >> m;

    if (m == 0) {
        cout << n + 1 << endl;
        return;
    }

    int ans = 0;
    map<char, vi> a;
    for (int i = 0; i < n; i++) {
        char side;
        int pos;
        cin >> side >> pos;
        a[side].push_back(pos);
    }

    map<char, vi> b;
    for (int i = 0; i < m; i++) {
        char side;
        int pos;
        cin >> side >> pos;
        b[side].push_back(pos);
    }

    vi cnt(sz(b['L']), n);

    sort(all(b['U']));
    sort(all(a['U']));

    for (auto pos: b['U']) {
        debug(pos);
        int cur = a['U'].end() - upper_bound(all(a['U']), pos) + sz(a['R']);
        cnt.push_back(cur);
    }

    debug(cnt);
    cnt.push_back(0);

    ans += n + 1;
    for (int i = 1; i < sz(cnt); i++) {
        ans += cnt[i - 1] + 1;
    }


    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}

