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

const int N = 2e5;
ll a[N], b[N];

void solve() {
    int n;
    cin >> n;
    set<int> s;
    map<int, int> fr;
    for (int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]), fr[a[i]]++;
    sort(a, a + n);

    ll ans = 0;

    for (auto i: s) {
        ans += max(0LL, fr[i] - fr[i - 1]);
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
