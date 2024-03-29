// ﷽
// https://codeforces.com/contest/1950/problem/D

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

vector<int> dp(1e5 + 1);

void solve() {
    int n;
    cin >> n;
    if (dp[n]) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    dp[0] = dp[1] = 1;
    for (int i = 0; i <= 1e5; i++) {
        if (!dp[i]) continue;
        for (int mask = 0; mask < 1 << 7; mask++) {
            int val = 0;
            for (int i = 0, x = 1; i < 7; i++, x *= 10) {
                if (mask >> i & 1) {
                    val += x;
                }
            }
            if (val * i <= 1e5) dp[val * i] = true;
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
