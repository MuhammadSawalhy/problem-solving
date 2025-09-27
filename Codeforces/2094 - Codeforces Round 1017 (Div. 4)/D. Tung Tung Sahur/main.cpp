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


void solve() {
    string p, s;
    cin >> p >> s;
    int i = 0, j = 0;
    if (p[0] == s[0])
        while (i < p.size() && j < s.size()) {
            debug(i, j);
            char other = p[i] == 'R' ? 'L' : 'R';
            int ii = find(p.begin() + i, p.end(), other) - p.begin();
            int jj = find(s.begin() + j, s.end(), other) - s.begin();

            int x = ii - i, y = jj - j;
            if (y < x || y > x * 2) break;

            i = ii;
            j = jj;
        }
    if (i == p.size() && j == s.size()) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
