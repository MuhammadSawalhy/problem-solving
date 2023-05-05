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

bool miller_rabin_ptest(unsigned ll n, int k = 10) {
    if (n < 2) return false;
    if (n == 2) return true;

    while (k--) {
        __int128 a = 1LL * rand() * rand() % (n - 2) + 2; // [2 ... n-1]
        __int128 r = 1;
        for (unsigned ll p = n - 1; p; p >>= 1) {
            if (p & 1) r = r * a % n;
            a = a * a % n;
        }
        if (r != 1) return false;
    }

    return true; // probably
}

void solve() {
    ll n;
    cin >> n;

    if (n & 1) {
        if (miller_rabin_ptest(n + 2)) {
            cout << 2 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }

    int i = 3;
    while (!miller_rabin_ptest(n + i)) {
        debug(i);
        do {
            i += 2;
        } while (!miller_rabin_ptest(i));
    }

    cout << i << endl;
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
