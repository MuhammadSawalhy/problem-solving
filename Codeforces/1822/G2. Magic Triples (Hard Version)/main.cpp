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

#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> fr;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    long long ans = 0;

    vector<pair<int, int>> vec;
    for (auto [x, f]: fr) {
        vec.emplace_back(x, f);
        ans += 1LL * (f) * (f - 1) * (f - 2);
    }

    int mx = vec.back().first;
    int threshold = pow(mx, 2.0 / 3);

    for (int j = 0; j < vec.size(); j++) {
        long long val = vec[j].first;
        if (val == 1) continue;
        if (val < threshold) {
            for (int factor = 2; factor * factor <= val; factor++) {
                if (val % factor) continue;
                if (fr.count(val / factor) && fr.count(val) && fr.count(val * factor))
                    ans += 1LL * fr[val / factor] * fr[val] * fr[val * factor];
                if (val / factor != factor)
                    if (fr.count(factor) && fr.count(val) && fr.count(val * val / factor))
                        ans += 1LL * fr[factor] * fr[val] * fr[val * val / factor];
            }
            if (fr.count(1) && fr.count(val) && fr.count(val * val))
                ans += 1LL * fr[1] * fr[val] * fr[val * val];
        } else {
            for (int b = 2; b * val <= mx; b++) {
                if (val % b == 0 && fr.count(val / b) && fr.count(val) && fr.count(val * b))
                    ans += 1LL * fr[val / b] * fr[val] * fr[val * b];
            }
        }
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
