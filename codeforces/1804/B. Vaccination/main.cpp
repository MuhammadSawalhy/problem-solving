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
const int N = 2e5;
int n, k, d, w;
int t[N];

void solve() {
    cin >> n >> k >> d >> w;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int ans = 0;
    int cnt = 0;
    int exp = 0;
    debug(n, k);
    for (int i = 0; i < n; i++) {
        debug(i, cnt, exp);
        if (cnt == 0 || exp < t[i]) {
            cnt = k;
            exp = t[i] + d + w;
            ans++;
        }

        cnt--;
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
