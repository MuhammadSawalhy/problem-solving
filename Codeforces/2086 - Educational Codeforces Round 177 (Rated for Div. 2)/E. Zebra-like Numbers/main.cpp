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


int zebra[63];

int get_zvalue(int x) {
    int cnt = 0;
    while (x) {
        int mx = 0;
        for (int i = 0; i < 63; i += 2)
            if (zebra[i] <= x) mx = i;
        x -= zebra[mx];
        cnt++;
    }
    return cnt;
}

int dp[63][2][2][63];
int l, r, k;

int rec(const int i, const bool L, const bool R, const int cnt) {
    if (i < 0) return cnt == k;
    auto &res = dp[i][L][R][cnt];
    if (res != -1) return res;
    res = 0;
    int taken = cnt * zebra[i];
    if (taken > (1LL << (i + 1))) return res;
    for (int d = (L ? (l >> i & 1) : 0); d <= (R ? (r >> i & 1) : 1); d++) {
        /*int cur = ((1LL * x) << (i + 2)) | ((1LL * y) << (i + 1)) | ((1LL * d) << i);*/
        if (taken & (1LL << i)) {

        }
        res += rec(i - 1, L && (d == (l >> i & 1)), R && (d == (r >> i & 1)), CNT);
        if (i % 2 == 0) {
            /*assert(X == 0);*/
        }
    }
    debug(i, L, R, cnt, res);
    return res;
}

void solve() {
    cin >> l >> r >> k;
    int ans = 0;
    /*for (int x = l; x <= r; x++) if (get_zvalue(x) == k) ans++;*/

    memset(dp, -1, sizeof dp);

    ans = rec(62, 1, 1, k);

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0, z = 0, sum = 0; i < 63; i += 2) {
        z <<= 2;
        z |= 1;
        zebra[i] = z;
        sum += z;
    }
    for (int i = 1; i < 63; i += 2) zebra[i] = zebra[i - 1];

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
