// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int n, m;

bool can(int n) {
    if (n == m) return true;
    if (n % 3) return false;
    bool c = can(n / 3);
    c |= can(n / 3 * 2);
    return c;
}

void solve() {
    cin >> n >> m;
    cout << (can(n) ? "YES" : "NO") << endl;
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
