// ﷽
// https://codeforces.com/contest/2013/problem/E

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5;
int a[mxN], dp[mxN + 1], dp2[mxN + 1], c[mxN + 1];
vector<int> f[mxN + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = mxN; i; --i)
        for (int j = i; j <= mxN; j += i)
            f[j].push_back(i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int g = 0, m = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            g = __gcd(g, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            a[i] /= g;
            m = max(a[i], m);
        }
        memset(c, 0, 4 * (m + 1));
        for (int i = 0; i < n; ++i)
            c[a[i]]++;
        for (int i = 1; i <= m; ++i)
            for (int j = 2 * i; j <= m; j += i)
                c[i] += c[j];
        for (int i = 2; i <= m; ++i) {
            dp[i] = 1e9;
            for (int j: f[i]) {
                dp2[j] = c[j];
                for (int k: f[i])
                    if (k > j && k % j == 0)
                        dp2[j] -= dp2[k];
                // cout << i << " " << j << " " << dp2[j] << " " << c[j] << endl;
                if (!dp2[j])
                    continue;
                dp[i] = min(dp[i], dp[j]);
            }
            dp[i] += i - 1;
        }
        // for(int i=1; i<=6;)
        // cout << dp[2] << " " << dp[6] << endl;
        ll ans = 1e9;
        for (int i = 0; i < n; ++i)
            ans = min(ans, (ll) dp[a[i]] + n);
        cout << ans * g << "\n";
    }
}

