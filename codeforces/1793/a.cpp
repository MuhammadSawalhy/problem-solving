// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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
    ll n, a, b, m;
    cin >> a >> b;
    cin >> n >> m;
    ll x = n / (m + 1) * (m + 1);
    ll y = n / (m + 1) * m * a;
    if (x < n) {
        y += min((n - x) * a, (n - x) * b);
    }
    cout << min(y, n * b) << endl;
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
