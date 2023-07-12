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
    cin >> n;
    int m;
    string s;
    int a = 1e9, b = 1e9, c = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        if (s[0] == '1') {
            a = min(a, m);
        }
        if (s[1] == '1') {
            b = min(b, m);
        }
        if (s[0] == '1' && s[1] == '1') {
            c = min(c, m);
        }
    }

    int ans = min(c, a + b);
    if (ans == 1e9)
        ans = -1;
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
