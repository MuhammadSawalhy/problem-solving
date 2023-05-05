// Date: 20-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif


long long cnt[121][121];

void count(long long t) {
    memset(cnt, 0, sizeof cnt);
    cnt[0][0] = t;
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 120; j++) {
            cnt[i + 1][j] += (cnt[i][j] + 0) / 2;
            cnt[i][j + 1] += (cnt[i][j] + 1) / 2;
        }
    }
}

void solve() {
    long long t, x, y;
    cin >> t >> x >> y;

    if (t < x + y) {
        cout << "NO\n";
        return;
    }

    count(max(0ll, t - x - y));
    long long a = cnt[x][y];
    count(max(0ll, t - x - y + 1));
    long long b = cnt[x][y];
    assert(b == a + 1 || b == a);
    debug(a, b);
    if (b == a + 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
