// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int mx = a.back();
    long long mn[2] = {(long long) 1e18, (long long) 1e18};
    long long toremove[2]{};

    auto process_toremove = [&](int m) {
        vector<int> b = a;
        for (int i = 0; i < n - m; i++) {
            b[i] = a[i] + n - m - i;
            mn[m] = min(b[i], mn[m]);
        }

        for (int i = 0; i < n - m; i++) {
            toremove[m] += b[i] - mn[m];
        }
    };

    if (n == 1) {
        while (q--) {
            int k;
            cin >> k;
            if (k & 1) {
                cout << a[0] + k - k / 2 << ' ';
            } else {
                cout << a[0] - k / 2 << ' ';
            }
        }
        return;
    }

    vector<int> ans(q);
    vector<pair<int, int>> k(q);
    for (int i = 0; i < q; i++)
        cin >> k[i].first, k[i].second = i;

    process_toremove(0);
    process_toremove(1);

    auto getans0 = [&](int k) -> int {
        int MN = mn[0] + (k - n);
        k -= n;
        if (toremove[0] >= k / 2) return MN;
        k -= toremove[0] * 2;
        return MN - (k + 2 * n - 1) / (2 * n);
    };

    auto getans1 = [&](int k) -> int {
        int MN = mn[1] + (k - (n - 1));
        int TR = toremove[1];

        if (MN < mx) {
            TR += mx - MN;
        } else {
            TR = TR + (n - 1) * (MN - mx);
            MN = mx;
        }

        k -= n - 1;
        if (TR >= k / 2) return MN;
        k -= TR * 2;
        return MN - (k + 2 * n - 1) / (2 * n);
    };

    vector<int> prefmin(n + 1, 1e18);

    for (int i = 0; i < n; i++) {
        prefmin[i + 1] = min(prefmin[i] + 1, a[i] + 1);
    }

    for (auto [K, i]: k) {
        if (K < n) {
            ans[i] = min(prefmin[K], a[K]);
        } else {
            if (K % 2 != n % 2) {
                ans[i] = getans1(K);
            } else {
                ans[i] = getans0(K);
            }
        }
    }

    for (auto a: ans)
        cout << a << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
