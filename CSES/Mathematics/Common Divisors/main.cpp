// ﷽
#include <bits/stdc++.h>

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

using namespace std;
int fr[1000001];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n; cin >> n; ll a;
    for (int i = 0; i < n; i++) cin >> a, fr[a]++;

    int ans = 1;
    for (int i = 2; i <= 1e6; i++) {
        int cnt = 0;
        for (int j = i; j <= 1e6; j+=i) cnt += fr[j];
        if (cnt > 1) ans = i;
    }

    cout << ans << endl;

    return 0;
}
