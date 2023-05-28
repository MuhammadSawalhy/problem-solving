// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a == vector<int>(n, a[0])) {
        cout << 1 << '\n';
        return;
    }

    int parts = 0;
    int i = 0;
    while (i + 1 < n && a[i + 1] == a[i])
        i++;
    bool inc = a[i + 1] > a[i];

    for (; i < n; i++) {
        int j = i;

        if (inc) {
            while (j + 1 < n && a[j + 1] >= a[j]) {
                j++;
            }
        } else {
            while (j + 1 < n && a[j + 1] <= a[j]) {
                j++;
            }
        }

        i = j;
        inc ^= 1;
        parts++;
    }

    cout << parts + 1 << '\n';
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
