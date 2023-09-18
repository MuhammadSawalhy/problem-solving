// ﷽
// https://codeforces.com/contest/1872/problem/0
// Codeforces -> Codeforces Round 895 (Div. 3) -> A. Two Vessels

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << ((abs(b - a) + 1) / 2 + c - 1) / c << endl;
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
