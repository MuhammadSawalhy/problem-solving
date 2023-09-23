// ﷽
// https://codeforces.com/contest/1873/problem/E
// Codeforces -> Codeforces Round 898 (Div. 4) -> E. Building an Aquarium

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = 0, e = 1e12 + 9;
    while (e - s > 1) {
        int mid = (s + e) / 2;
        int needed = 0;
        for (int i = 0; i < n; i++) {
            needed += max(0LL, mid - a[i]);
        }

        if (needed <= x) {
            s = mid;
        } else {
            e = mid;
        }
    }

    cout << s << endl;
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
