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
    int a, b;
    long long l = 1, g = 0;
    int ans = 1;
    for (int i = 0;i < n; i++) {
        cin >> a >> b;
        g = gcd(g, b * a);
        l = lcm(l, b);
        if (g % l != 0) {
            ans++;
            g = b * a;
            l = b;
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
