// ﷽
// https://codeforces.com/contest/1913/problem/B

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int fr[2]{};
    int fr2[2]{};
    for (int i = 0; i < n; i++) {
        fr[s[i] - '0']++;
    }

    int ans = 1e9;

    for (int i = 0; i <= n; i++) {
        if (fr[1] >= fr2[0] && fr[0] >= fr2[1])
            ans = min(ans, fr[1] - fr2[0] + fr[0] - fr2[1]);
        fr2[s[i] - '0']++;
    }

    cout << ans << endl;
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
