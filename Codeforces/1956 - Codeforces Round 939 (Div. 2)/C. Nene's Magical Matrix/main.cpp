// ﷽
// https://codeforces.com/contest/1956/problem/C

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

    int sum = 0;
    vector<vector<int>> ans;
    vector<int> p(n + 2);
    iota(p.begin() + 2, p.end(), 1);
    for (int i = n; i >= 1; i--) {
        sum += (i * i - (i - 1) * (i - 1)) * i;
        p[0] = 1;
        p[1] = i;
        ans.push_back(p);
        p[0] = 2;
        p[1] = i;
        ans.push_back(p);
    }

    cout << sum << ' ' << sz(ans) << endl;
    for (auto &x: ans) {
        for (auto i: x) cout << i << ' ';
        cout << endl;
    }
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
