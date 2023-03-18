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
    ll k;
    cin >> k;
    k = abs(k);
    ll s = 0, e = 1e6;
    while (e - s > 1) {
        ll m = (s + e) / 2;
        if (m * (m + 1) / 2 >= k) {
            e = m;
        } else {
            s = m;
        }
    }

    // find n >= e which will give a arithmetic sum (1...n) with the same parity as k

    while (true) {
        if ((e * (e + 1) / 2 % 2) == k % 2) {
            cout << e << endl;
            break;
        }
        e++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t) cout << endl;
    }

    return 0;
}
