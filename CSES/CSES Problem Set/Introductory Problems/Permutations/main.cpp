// Date: 01-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n < 4) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int mx = n, mn = (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            cout << mx << " ";
            mx--;
        } else {
            cout << mn << " \n"[mn == 1];
            mn--;
        }
    }

    return 0;
}
