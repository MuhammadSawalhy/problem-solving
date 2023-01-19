// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    set<int> s;
    map<int, int> fr;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && (s.size() < k || s.size() == k && s.count(a[r]))) {
            s.insert(a[r]);
            fr[a[r]]++;
            r++;
        }
        debug(l, r, s.size());

        ans += r - l;
        if (--fr[a[l]] == 0) s.erase(a[l]);
    }

    cout << ans;

    return 0;
}
