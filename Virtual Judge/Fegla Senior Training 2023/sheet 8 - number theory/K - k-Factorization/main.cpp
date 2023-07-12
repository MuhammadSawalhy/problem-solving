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

    int n, k;
    cin >> n >> k;

    auto pf = primefacts(n);

    int cnt = 0;
    for (auto [p, f] : pf) {
        cnt += f;
    }

    if (cnt < k) {
        cout << -1 << endl;
        return 0;
    } else {
        for (auto [p, f] : pf) {
            while (f--) {
                if (k == 1) break;
                cout << p << ' ';
                n /= p;
                k--;
            }
            if (k == 1) break;
        }
    }

    cout << n << endl;

    return 0;
}
