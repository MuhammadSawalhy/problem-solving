// ﷽
#include <bits/stdc++.h>

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

using namespace std;

constexpr int mod = 1e9 + 7;

int power(int a, int b, int mod) {
    int r;
    for (r = 1; b; b >>= 1) {
        if (b & 1)
            r = (a * r) % mod;
        a = (a * a) % mod;
    }
    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    ll a, b, c, res, r;
    while (t--) {
        cin >> a >> b >> c;
        cout << power(a, power(b, c, mod - 1), mod) << endl;
    }

    return 0;
}
