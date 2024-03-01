// ﷽
// https://codeforces.com/contest/1915/problem/B

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
    char ans;
    for (int i = 0; i < 3; i++) {
        cin >> s;
        set<char> ss{'A', 'B', 'C'};
        for (int j = 0; j < 3; j++) {
            if (s[j] != '?') ss.erase(s[j]);
        }
        if (ss.size()) ans = *ss.begin();
    }
    cout << ans << '\n';
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
