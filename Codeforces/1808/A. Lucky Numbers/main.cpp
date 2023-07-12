// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

vector<int> dig(int x) {
    vector<int> ret;
    while (x) {
        ret.push_back(x % 10);
        x /= 10;
    }
    return ret;
}

void solve() {
    int l, r;
    cin >> l >> r;

    int mx = -1, ans;
    debug(dig(150));
    for (int i = l; i <= r; i++) {
        vector<int> d = dig(i);
        int a = *max_element(all(d)) - *min_element(all(d));
        if (a > mx) {
            mx = a;
            ans = i;
        }
        if (mx == 9) break;
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
