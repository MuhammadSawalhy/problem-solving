// ﷽
// https://codeforces.com/contest/1901/problem/C

#include <algorithm>
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    int ops = 0;

    vector<int> ans;
    while (mx != mn) {
        ops++;
        if (mn & 1) mn++, mx++, ans.push_back(1);
        else ans.push_back(0);
        mx /= 2;
        mn /= 2;
    }

    cout << ans.size() << endl;
    if (ans.size() && ans.size() <= n) {
        for (auto i: ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
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
