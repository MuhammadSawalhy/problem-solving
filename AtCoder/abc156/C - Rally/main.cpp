// ﷽
#include <iostream>
#include <limits.h>

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

const int N = 1000;
int n;
ll a[N];

ll calc(ll p) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] - p) * (a[i] - p);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

    ll ans = LONG_LONG_MAX;

    ans = min(ans, calc(sum / n + 1));
    ans = min(ans, calc(sum / n - 1));
    ans = min(ans, calc(sum / n));

    cout << ans << endl;

    return 0;
}
