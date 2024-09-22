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

// #include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// using namespace std;
//
// #ifdef SAWALHY
// #include "debug.hpp"
// #else
// #define debug(...) 0
// #define debug_itr(...) 0
// #define debug_bits(...) 0
// #endif
//
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define pii pair<int, int>
// #define sz(v) (int) (v).size()
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define minit(v, x...) v = min({v, x})
// #define maxit(v, x...) v = max({v, x})
//
// template<class T>
// using rpq = priority_queue<T, vector<T>, greater<T>>;
//
// const int N = 1e5 + 1;
// vector<int> fact[N];
//
// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
// }
//
// int32_t main(int32_t argc, char **argv) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);
//
//     int mx = 0, sm = 0;
//     for (int i = 1; i < N; i++) {
//         for (int j = i; j < N; j += i) {
//             fact[j].push_back(i);
//         }
//     }
//
//     for (int i = 1; i < N; i++) {
//         sm += sz(fact[i]) * (sz(fact[i]) - 1) / 2;
//         maxit(mx, sz(fact[i]));
//     }
//
//     debug(mx, sm);
//
//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve();
//
//     return 0;
// }
