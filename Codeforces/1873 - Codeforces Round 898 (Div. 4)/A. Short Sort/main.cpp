// ﷽
// https://codeforces.com/contest/1873/problem/0
// Codeforces -> Codeforces Round 898 (Div. 4) -> A. Short Sort

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
    string s;
    cin >> s;
    int pos[3] = {0, 1, 2};
    int change = 0;
    for (int i = 0; i < 3; i++) {
        change += pos[s[i] - 'a'] != i;
    }

    if (change <= 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
