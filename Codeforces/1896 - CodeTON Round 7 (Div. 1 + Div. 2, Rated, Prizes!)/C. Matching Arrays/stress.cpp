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
#define all(v) v.begin(), v.end()

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    do {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += a[i] > b[i];
        }

        if (ans == x) {
            cout << "YES" << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << b[i] << " \n"[i == n - 1];
            // }
            return;
        }
    } while (next_permutation(b, b + n));
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
