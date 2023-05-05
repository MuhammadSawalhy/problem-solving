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

vector<int> factors(int x) {
    vector<int> facts;
    for (int i = 1; i * i <= x; i++) {
        if (x % i) continue;
        facts.push_back(i);
        if (i != x / i)
            facts.push_back(x / i);
    }
    return facts;
}

void solve() {
    int n;
    cin >> n;
    ll a[n];
    map<int, int> fr;
    for (int i = 0; i < n; i++) cin >> a[i], fr[a[i]]++;

    int diff = 0;
    int ans = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        diff += a[i] != a[j];
        ans = gcd(ans, abs(a[i] - a[j]));
    }

    if (diff == 0) {
        cout << "0\n";
        return;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            for (auto f: factors(j - i)) {
                if (j % f != i % f) {
                    debug(j, i, f);
                    return 0;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
