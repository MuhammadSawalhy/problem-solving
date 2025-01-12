// ﷽
// https://codeforces.com/contest/2053/problem/C

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

int n, k;
map<int, pair<int, int>> mp;

pair<int, int> rec(int n) {
    if (n < k) return {0, 0};
    if (mp.count(n)) return mp[n];
    auto &ans = mp[n];

    int m = (n + 1) / 2;
    if (n & 1) {
        auto x = rec(m - 1);
        ans = x;

        ans.first += m;
        ans.second += 1;

        ans.first += x.first + (x.second) * m;
        ans.second += x.second;
    } else {
        auto x = rec(m);
        ans = x;
        ans.first += x.first + (x.second) * m;
        ans.second += x.second;
    }

    return ans;
}

void solve() {
    cin >> n >> k;
    auto p = rec(n);
    cout << p.first << endl;
    mp.clear();
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
