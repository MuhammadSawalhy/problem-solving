#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

const int N = 20;
int dp[1 << N][2][2];
int val[1 << N];
int a[N];
int n, x, y;

bool check() {
    memset(dp, 0, sizeof dp);
    bool ret = false;
    dp[0][0][0] = 1;
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            int newmask = mask ^ (1 << i);
            int newcur = val[newmask];
            if (mask >> i & 1) continue;
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int J = j || (newcur == x);
                    int K = k || (newcur == y);
                    dp[newmask][J][K] |= dp[mask][j][k];
                }
            }
        }
        ret |= dp[mask][1][1];
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x >> y;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));
    n = unique(all(a)) - a;
    n = min(n, N);

    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++)
            if (mask >> i & 1) val[mask] ^= a[i];
    }

    bool can = check();
    swap(x,y);
    can |= check();

    if (can) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
