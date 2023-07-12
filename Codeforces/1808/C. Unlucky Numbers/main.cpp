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

string L, R;
ll p[19];

vector<int> dig(int x) {
    vector<int> ret;
    while (x) {
        ret.push_back(x % 10);
        x /= 10;
    }
    return ret;
}

ll get_val(int m, int M, int i, bool isl, bool isr) {
    if (i == L.size()) return 0;
    int dl = L[i] - '0', dr = R[i] - '0';
    for (int d = (isl ? dl : 0); d <= (isr ? dr : 9); d++) {
        if (d < m || d > M) continue;
        ll val = get_val(m, M, i + 1, isl & (d == dl), isr & (d == dr));
        if (val == -1) continue;
        return val + d * p[L.size() - 1 - i];
    }
    return -1;
}

void solve() {
    int l, r;
    cin >> l >> r;

    auto dl = dig(l);
    auto dr = dig(r);

    if (dl.size() < dr.size()) {
        cout << string(dl.size(), '9') << '\n';
        return;
    }

    assert(dl.size() == dr.size());
    L = to_string(l);
    R = to_string(r);

    for (int diff = 0; diff < 10; diff++) {
        for (int m = 0; m < 10; m++) {
            int M = m + diff;
            // for each digit d, m <= d <= M
            ll val = get_val(m, M, 0, true, true);
            if (val != -1)
                return cout << val << '\n', void();
        }
    }

    assert(false);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    p[0] = 1;
    for (int i = 1; i < 19; i++)
        p[i] = p[i - 1] * 10;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
