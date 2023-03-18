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

map<ll, ll> primefacts(ll n) {
    map<ll, ll> result;
    int r = 0;

    while (n % 2 == 0) {
        r++;
        n = n / 2;
    }

    if (r > 0)
        result[2] = r;

    int sqn = sqrt(n);
    for (int i = 3; i <= sqn; i += 2) {
        r = 0;
        while (n % i == 0) {
            r++;
            n = n / i;
        }
        if (r > 0)
            result[i] = r;
    }

    if (n > 2)
        result[n] = 1;

    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    while (cin >> n, n) {
        auto primes = primefacts(n);
        vector<int> fr;
        long long x = 0;
        int m = primes.size();
        for (auto [p, f] : primes) fr.push_back(f);
        for (int i = 0; i < 1 << m; i++) {
            long long y = 1;
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    y *= (fr[j]);
                } else {
                    y *= (fr[j] + 1);
                }
            }
            x += y;
        }
        cout << n << " " << 1LL + x / 2 << endl;
    }

    return 0;
}
