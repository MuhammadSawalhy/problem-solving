// بسم الله الرحمن الرحيم
// https://codeforces.com/contest/1878/problem/F
// Codeforces -> Codeforces Round 900 (Div. 3) -> F. Vasilije Loves Number Theory

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

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

void solve() {
    int n, q;
    cin >> n >> q;

    auto ini_primes = primefacts(n);
    auto primes = ini_primes;

    int d = 1;
    for (auto [p, f]: primes) {
        d *= f + 1;
    }

    int ini_d = d;
    int ini_n = n;

next:
    while (q--) {
        int t;
        cin >> t;

        if (t == 2) {
            primes = ini_primes;
            d = ini_d;
            n = ini_n;
            continue;
        }

        int x;
        cin >> x;
        n *= x;
        auto x_primes = primefacts(x);

        for (auto [p, f]: x_primes) {
            int prev = primes[p];
            primes[p] += f;
            d /= prev + 1;
            d *= (prev + f) + 1;
        }

        auto d_primes = primefacts(d);

        debug(n, d);
        debug(primes, d_primes);

        for (auto [p, f]: d_primes) {
            auto it = primes.find(p);
            if (it == primes.end() || it->second < f) {
                cout << "NO\n";
                goto next;
            }
        }

        cout << "YES\n";
    }
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
