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

#define int __int128
#define ll long long
#define all(v) v.begin(), v.end()

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    int l = 1;
    int base = 0;

    ll a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        // (base - 0.5 * a[i]) is divisible by gcd(l, a[i])
        // extended euclidean algorithm

        int x, y;
        int gcd = gcdExtended(l, a[i], &x, &y);

        int z = (max((int) 0, base - a[i] / 2) + a[i] - 1) / a[i] * a[i] + a[i] / 2;

        if ((z - base) % gcd != 0) {
            cout << 0 << endl;
            exit(0);
        }

        x *= (z - base) / gcd;
        y *= (z - base) / gcd;

        assert(base + x * l == z - y * a[i]);
        ll newbase = z - y * a[i];
        l = l * a[i] / gcd;
        newbase = newbase + (max((int) 0, base - newbase) + l - 1) / l * l;
        newbase -= (newbase - base) / l * l;
        base = newbase;

        if (base > m) {
            cout << 0 << endl;
            exit(0);
        }
    }

    cout << (ll) ((m - base) / l) + 1 << endl;

    return 0;
}

// 3 5985
// 30 14 38
