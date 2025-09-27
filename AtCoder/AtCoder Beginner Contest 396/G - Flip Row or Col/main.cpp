#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

const int N = 1 << 19;
int dp[N][19];

void solve() {
    int h, w;
    cin >> h >> w;

    string s;
    for (int i = 0; i < h; i++) {
        cin >> s;
        int x = stoi(s, nullptr, 2);
        dp[x][0]++;
    }

    for (int j = 0; j < w; j++) {
        for (int k = w - 1; k >= 0; k--) {
            for (int i = 0; i < 1 << w; i++) {
                dp[i][k + 1] += dp[i ^ (1 << j)][k];
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 1 << w; i++) {
        int cur = 0;
        for (int k = 0; k <= w; k++)
            cur += dp[i][k] * min(k, w - k);
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
