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
    int n;
    cin >> n;
    vector<int> a(n), fr(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    int ans = 1;
    set<int> s;
    int j = 0;
    debug(a);
    for (int i = 0; i + 1 < n; i++) {
        fr[a[i]]--;
        if (fr[a[i]] == 0) break;
        // the rest are ok
        s.erase(a[i]);
        debug(i, a[i], s);
        if (s.size() == 0) {
            // can make a segment
            debug("seg");
            ans++;
            for (int k = j; k <= i; k++) {
                s.insert(a[k]);
            }
            j = i + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
