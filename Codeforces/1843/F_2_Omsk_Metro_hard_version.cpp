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

void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> values(2);
    values[1] = {0, 1, 0, 1};

    char t;
    while (n--) {
        cin >> t;
        if (t == '+') {
            int v, x;
            cin >> v >> x;
            int minsuffix = min(min(values[v][0], 0LL) + x, 0LL);
            int maxsuffix = max(max(values[v][1], 0LL) + x, 0LL);
            int minseg = min(values[v][2], minsuffix);
            int maxseg = max(values[v][3], maxsuffix);
            values.push_back({ minsuffix, maxsuffix, minseg, maxseg });
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            debug(values[v]);
            if (values[v][2] <= k && k <= values[v][3]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
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
