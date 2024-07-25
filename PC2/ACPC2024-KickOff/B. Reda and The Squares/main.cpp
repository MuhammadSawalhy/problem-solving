#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)


int sq(int x) {
    int s = sqrt(x);
    while (s * s < x) s++;
    while (s * s > x) s--;
    return s;
}

void solve() {
    int n;
    cin >> n;

    int ans = n;
    for (int x = 0; x * x <= n * 2; x++) {
        int d = max(0ll, n - x * x);
        int y = sq(d);
        ans = min(ans, abs(x * x + y * y - n));
        y++;
        ans = min(ans, abs(x * x + y * y - n));
    }

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
