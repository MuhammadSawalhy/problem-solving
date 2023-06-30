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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) continue;
        ll sum = a[i];
        bool ok = true;
        for (int j = (i + 1) % n; i != j; j = (j + 1) % n) {
            sum += a[j];
            if (sum < 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
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

