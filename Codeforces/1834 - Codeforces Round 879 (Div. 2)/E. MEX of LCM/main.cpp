// ﷽
// https://codeforces.com/contest/1834/problem/E

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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> lcms{1};

    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> vals;

    for (int i = 0; i < n; i++) {
        for (auto &l: lcms) l = lcm(l, a[i]);
        lcms.push_back(a[i]);
        sort(all(lcms));
        lcms.resize(unique(all(lcms)) - lcms.begin());
        lcms.resize(remove_if(all(lcms), [n](int x) { return x > n * n + 1; }) - lcms.begin());
        for (auto l: lcms) vals.insert(l);
    }

    int ans = 1;
    auto it = vals.begin();
    while (it != vals.end() && ans == *it) ans++, it++;
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
