// ﷽
// 11 جُمادى الآخرة 1444
// Jan 03, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "YES" << endl;
        int x = 1;
        for (int i = 0; i < n; i++) {
            cout << x << " \n"[i == n - 1];
            x *= -1;
        }
    } else {
        if (n == 3)
            cout << "NO" << endl;
        else {
                int b = n / 2;
                int a = - (n / 2 - 1);
                cout << "YES" << endl;
                for (int i = 0; i < n; i++) {
                    if (i & 1) {
                        cout << b << " ";
                    } else {
                        cout << a << " ";
                    }
                }
                cout << endl;
        }
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
