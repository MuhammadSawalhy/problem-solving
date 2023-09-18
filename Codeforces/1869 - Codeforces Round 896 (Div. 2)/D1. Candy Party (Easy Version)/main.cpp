// ﷽
// https://codeforces.com/contest/1869/problem/D1
// Codeforces -> Codeforces Round 896 (Div. 2) -> D1. Candy Party (Easy Version)

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

pair<int, int> combute(int x) {
    for (int i = 1; i < 1 << 30; i <<= 1) {
        for (int j = 1; j < 1 << 30; j <<= 1) {
            if (x + i - j == 0)
                return {i, j};
        }
    }

    return {-1, -1};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n) {
        cout << "No\n";
        return;
    }

    const int y = sum / n;
    vector<int> diff(n, -y);
    map<int, int> fr;

    for (int i = 0; i < n; i++) {
        diff[i] += a[i];
        int d = abs(diff[i]);
        if (d == 0) continue;
        auto [in, out] = combute(d);
        if (in == -1) {
            cout << "No\n";
            return;
        }
        if (diff[i] < 0) swap(in, out);
        fr[in]++;
        fr[out]--;
    }

    bool ok = true;
    for (auto [x, f]: fr) {
        ok &= f == 0;
    }

    sort(all(diff));
    debug(fr);
    debug(diff);

    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
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
