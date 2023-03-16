// ﷽
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
    int a, b; cin >> a >> b;
    a = abs(a), b = abs(b);
    if (a < b) swap(a, b);
    if (a == b) { return cout << a * 2 << endl, void(); }
    a -= b;

    cout << b * 2 + 1 + (a - 1) * 2 << endl;
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
