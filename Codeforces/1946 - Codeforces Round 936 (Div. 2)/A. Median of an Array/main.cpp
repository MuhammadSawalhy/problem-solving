// ﷽
// https://codeforces.com/contest/1946/problem/A

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

    int ind = (n + 1) / 2;
    ind--;

    sort(all(a));

    int j = upper_bound(all(a), a[ind]) - a.begin();
    cout << j - ind << endl;

}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // stress(argc, argv);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
