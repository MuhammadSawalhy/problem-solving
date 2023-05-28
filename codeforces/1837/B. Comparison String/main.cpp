// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int mx = 0;

    int cur = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            mx = max(mx, cur);
            cur = 1;
        }
    }

    mx = max(mx, cur);

    cout << mx + 1 << '\n';
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
