// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int mn = 1;
    int mx = n;
    int l = 0;
    int r = n - 1;

    while (l < r && (p[l] == mn || p[r] == mn || p[l] == mx || p[r] == mx)) {
        if (p[l] == mn) {
            l++;
            mn++;
            continue;
        }
        if (p[r] == mn) {
            r--;
            mn++;
            continue;
        }
        if (p[l] == mx) {
            l++;
            mx--;
            continue;
        }
        if (p[r] == mx) {
            r--;
            mx--;
            continue;
        }
    }

    if (l < r) {
        cout << l + 1 << " " << r + 1 << endl;
    } else {
        cout << -1 << endl;
    }
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
