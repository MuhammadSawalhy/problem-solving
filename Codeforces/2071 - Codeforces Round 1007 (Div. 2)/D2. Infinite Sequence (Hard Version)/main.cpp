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


    function<int(int)> s = [&](int m) {
        int sum = 0;

        for (int i = 1; i < min(m + 1, n); i++) {
            sum += a[i];
        }

        if (m >= n) {
            for (int m_ = 0; m_ < n; m_++) {
                if (m_ * 2 < n) continue;
                int mm = m_ * 2;
                int cur = sx[m_];
                while (mm <= m) {
                    if (mm + 1 <= m) sum += cur;
                    sum += cur;
                    mm *= 2;
                    cur ^= sx[n - 1];
                }
            }

            int p = 1;
            int cur = sx[n - 1];
            while (true) {
                p *= 2;
                // count of m_ (odd >= n) such that m_*p <= m
                int cnt = (m / p + 1) / 2 - n / 2;
                if (cnt <= 0) break;
                sum += cnt * cur;
                // count of m_ (odd >= n) such that m_*p+1 <= m
                cnt = ((m - 1) / p + 1) / 2 - n / 2;
                if (cnt > 0) sum += cnt * cur;
                cur ^= sx[n - 1];
            }
        }


        return sum;
    };

    // vector<int> b(1000);
    // for (int i = 0; i < n; i++) b[i] = a[i];
    // for (int i = n, j = 0, x = 0; i < b.size(); i++) {
    //     while (j <= i / 2) x ^= b[j++];
    //     b[i] = x;
    //     assert(b[i] == s(i) - s(i - 1));
    // }

    debug(r, s(r));
    debug(l - 1, s(l - 1));
    cout << s(r) - s(l - 1) << endl;
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
