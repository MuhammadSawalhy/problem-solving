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

struct mul {
    ll operator()(int a, int b) {
        return 1LL * a * b;
    }

    friend int identity_element(const mul &) {
        return 1;
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    ll a[n], A[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    A[0] = a[0];

    for (int i = 1; i < n; i++)
        A[i] = a[i] + A[i - 1];

    auto count = [&](ll x) -> ll {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] + a[i] < x) continue;
            int j = lower_bound(a, a + n, x - a[i]) - a;
            cnt += 1LL * (i - j) * 2 + 1;
        }
        return cnt;
    };

    auto sum = [&](ll x) -> ll {
        ll s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] + a[i] < x) continue;
            int j = lower_bound(a, a + n, x - a[i]) - a;
            s += 1LL * (i > 0 ? A[i - 1] - (j > 0 ? A[j - 1] : 0) : 0) * 2 + 1LL * (i - j + 1) * a[i] * 2;
        }
        return s;
    };

    // bs the mth value
    ll s = 0, e = 1e18;
    while (e - s > 1) {
        ll x = (s + e) / 2;
        if (count(x) >= m) {
            s = x;
        } else {
            e = x;
        }
    }

    cout << (m - count(s + 1)) * s + sum(s + 1);

    return 0;
}
