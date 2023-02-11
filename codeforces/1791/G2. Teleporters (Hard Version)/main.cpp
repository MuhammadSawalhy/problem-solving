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
    int n, c, C;
    cin >> n >> c, C = c; 
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = min(a[i] + i + 1, a[i] + (n - i));
        a[i] = a[i] + i + 1;
    }

    vector<int> order(n);
    iota(all(order), 0);

    sort(all(order), [&](int l, int r) { return b[l] < b[r]; });

    int i = 0;
    while (i < n && b[order[i]] <= c) {
        c -= b[order[i++]];
    }

    // try to replace one to with the value from the left
    // or choose another one which is maller
    // if you can't, subtract 1

    bool ok = false;

    multiset<int> ms;
    for (int j = i; j < n; j++) {
        ms.insert(a[order[j]]);
    }

    for (int j = 0; j < i; j++) {
        ms.insert(a[order[j]]);
        int mn = *ms.begin();
        if (c + b[order[j]] >= mn) {
            ok = true;
            break;
        }
        ms.erase(ms.find(a[order[j]]));
    }


    if (!ok && i > 0) {
        int j = min_element(a, a + n) - a;
        c = C;
        c -= a[j];
        if (c < 0) {
            cout << 0 << endl;
            return;
        }
        int i = 0;
        int ans = 1;
        while (i < n && b[order[i]] <= c) {
            if (order[i] == j) {
                i++;
                continue;
            }
            ans++;
            c -= b[order[i++]];
        }
        cout << ans << endl;
        return;
    }

    cout << i - (!ok && i > 0) << endl;
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
