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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int x;
    for (int i = 0;i  < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x) {
                cout << char('A' + (x - 1));
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}
