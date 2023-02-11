// ﷽
#include <iostream>

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
    int n, r;
    cin >> n >> r;

    if (n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
        solve();

    return 0;
}
