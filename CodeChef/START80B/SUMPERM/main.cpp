// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;

    if (n & 1)  {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n / 2; i++) {
        cout << 2 * i + 2 << " " << 2 * i + 1 << " ";
    }

    cout << "\n";
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
