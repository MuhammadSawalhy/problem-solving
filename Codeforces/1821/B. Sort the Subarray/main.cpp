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
    int a[n], b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            int j = i, k = i;
            while (j > 0 && b[j - 1] <= b[j]) j--;
            while (k < n - 1 && b[k] <= b[k + 1]) k++;
            cout << j + 1 << ' ' << k + 1 << '\n';
            return;
        }
    }

    cout << "1 " << n << '\n';
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
