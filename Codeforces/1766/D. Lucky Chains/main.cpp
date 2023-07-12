// Date: 12-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

int N = 1e7 + 1;
vector<int> mp(N);

void solve() {
    int x, y;
    cin >> x >> y;
    int d = y - x;

    if (gcd(x, y) > 1) {
        cout << 0 << '\n';
        return;
    }

    if (d == 1) {
        cout << -1 << '\n';
        return;
    }

    int k = 1e9;
    while (d > 1) {
        int p = mp[d];
        d /= p;
        k = min(k, p - (x % p));
    }

    cout << k << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // calculate minimum prime factor to do fast factorization later
    for (int i = 2; i < N; i++) {
        if (!mp[i]) {
            mp[i] = i;
            for (int j = i + i; j < N; j += i) {
                if (!mp[j])
                    mp[j] = i;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
