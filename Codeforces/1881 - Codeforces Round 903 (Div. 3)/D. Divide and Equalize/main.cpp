// ﷽
// https://codeforces.com/contest/1881/problem/D

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> fr;
    for (int i = 0; i < n; i++) {
        auto primes = primefacts(a[i]);
        for (auto [x, f]: primes) fr[x] += f;
    }

    for (auto [x, f]: fr) {
        if (f % n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
