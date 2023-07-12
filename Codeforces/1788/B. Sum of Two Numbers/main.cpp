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

    int a = 0, b = 0;
    int p = 1;

    bool who = 0;
    while (n) {

        if ((n % 10) % 2 == 1) {
            if (who) {
                a += (n % 10 / 2) * p;
                b += ((n % 10 + 1) / 2) * p;
            } else {
                b += (n % 10 / 2) * p;
                a += ((n % 10 + 1) / 2) * p;
            }
            who ^= 1;
        } else {
            a += (n % 10 / 2) * p;
            b += (n % 10 / 2) * p;
        }

        p *= 10;
        n /= 10;
    }

    cout << a << " " << b << endl;
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
