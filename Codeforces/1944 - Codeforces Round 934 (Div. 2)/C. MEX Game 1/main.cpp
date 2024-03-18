// ﷽
// https://codeforces.com/contest/1944/problem/C

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> fr;
    for (int i = 0; i < n; i++) cin >> a[i], fr[a[i]]++;

    vector<int> one;
    for (auto [x, f]: fr) {
        if (f == 1) one.push_back(x);
    }

    if (one.size() > 1) {
        a.erase(find(all(a), one[1]));
    }

    // find mex
    fr.clear();
    for (auto x: a) fr[x]++;
    int mex = 0;
    while (fr[mex]) mex++;
    cout << mex << endl;
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
