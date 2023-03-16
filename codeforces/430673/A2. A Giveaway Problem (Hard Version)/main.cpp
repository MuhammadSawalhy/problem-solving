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

void solve() {
    int n;
    cin >> n;
    ll q[n];
    for (int i = 0; i < n; i++) cin >> q[i];

    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }

    for (int i = 0; i < n; i++) {
        if (q[i] != 0)
            s.erase(q[i]);
    }

    for (int i = 0; i < n; i++) {
        if (q[i] == 0) {
            q[i] = *s.begin();
            s.erase(s.begin());
        }
        cout << q[i] << " ";
    }
    cout << "\n";
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
