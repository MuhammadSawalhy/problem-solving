#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    // l == r

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int N = 1;
    while (N <= n) N *= 2;
    a.resize(N);

    for (int i = n + 1, j = 0, x = 0; i < N; i++) {
        while (j <= i / 2) x ^= a[j++];
        a[i] = x;
    }

    n = N;
    debug(n, a);

    vector<int> sx(n);
    for (int i = 1; i < n; i++) {
        sx[i] = sx[i - 1] ^ a[i];
    }

    function<int(int)> f = [&](int m) {
        if (m < n) return a[m];
        // a[1] ^ a[2] ^ ... ^ a[m / 2]

        m /= 2;
        if (m < n) return sx[m];
        if (m & 1) return sx[n - 1];
        return sx[n - 1] ^ f(m);
    };

    function<int(int)> f2 = [&](int m) {
        if (m < n) return a[m];
        // a[1] ^ a[2] ^ ... ^ a[m / 2]

        int ans = 0;
        m /= 2;

        while (m >= n && m % 2 == 0) {
            ans ^= sx[n - 1];
            m /= 2;
        }

        if (m < n) ans ^= sx[m];
        else if (m & 1) ans ^= sx[n - 1];
        return ans;
    };

    vector<int> b(1e6);
    for (int i = 0; i < n; i++) b[i] = a[i];
    for (int i = n, j = 0, x = 0; i < 1e6; i++) {
        while (j <= i / 2) x ^= b[j++];
        b[i] = x;
        assert(b[i] == f2(i));
    }

    cout << f2(l) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-------------", t);
        solve();
    }

    return 0;
}
