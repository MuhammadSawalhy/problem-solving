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

map<ll, ll> primefacts(ll n) {
    map<ll, ll> result;
    int r = 0;

    while (n % 2 == 0) {
        r++;
        n = n / 2;
    }

    if (r > 0)
        result[2] = r;

    for (int i = 3; i * i <= n; i += 2) {
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
    ll n;
    cin >> n;

    auto facts = primefacts(n);

    vector<pair<ll, ll>> f;

    for (auto [p, cnt]: facts) {
        f.emplace_back(cnt, p);
    }

    sort(all(f), greater<pair<ll, ll>>());
    vector<ll> ans;

    cout << f[0].first << '\n';

    for (int i = 0; i < f[0].first - 1; i++) {
        cout << f[0].second << ' ', n /= f[0].second;
    }

    cout << n << '\n';

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
