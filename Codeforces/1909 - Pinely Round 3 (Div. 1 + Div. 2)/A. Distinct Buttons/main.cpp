// ﷽
// https://codeforces.com/contest/1909/problem/0

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
    set<char> s;
    bool up = true, right = true, left = true, down = true;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        up &= y >= 0;
        down &= y <= 0;
        right &= x >= 0;
        left &= x <= 0;
    }

    if (up || down || right || left) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
