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

int solve(int d, const vector<int> &fr) {
    int ans = 0;
    for (int cnt = 1; cnt * d <= 2000; cnt++) {
        int part_len = 0;
        for (auto f: fr) {
            part_len += f / cnt;
        }
        if (part_len < d) part_len = 0;
        ans = max(ans, min(d, part_len) * cnt);
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> fr(26);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        fr[c - 'a']++;
    }

    sort(all(fr));

    int ans = 0;
    for (int d = 1; d * d <= k; d++)
        if (k % d == 0) {
            ans = max(ans, solve(d, fr));
            ans = max(ans, solve(k / d, fr));
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
