#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1, n, m, k, cur;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k, cur = 0;
        for (int i = 0; i < n; ++i, !(m % k) && (cur = i)) {
            for (int j = 0; j < m; j++)
                cout << cur++ % k + 1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}
