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

void solve() {
    int n; cin >> n; ll a[n];
    map<int, int> fr;
    for (int i = 0; i < n; i++) cin >> a[i], fr[a[i]]++;
    if (fr.size() == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    sort(a, a + n);
    reverse(a + 1, a + n);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
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
