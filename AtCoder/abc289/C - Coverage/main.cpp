// ﷽
#include <iostream>
#include <set>
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    std::set<int> s[m];

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0, a; j < c; j++) {
            cin >> a;
            s[i].insert(a);
        }
    }

    int ans = 0;
    for (int i = 1; i < 1 << m; i++) {
        vector<bool> ok(n + 1);
        for (int j = 0; j < m; j++) {
            if (i >> j & 1 ^ 1) continue;
            for (int k = 1; k <= n; k++) {
                ok[k] = ok[k] || s[j].count(k);
            }
        }

        bool OK = true;
        for (int k = 1; k <= n; k++)
            OK = OK && ok[k];

        ans += OK;
    }

    cout << ans << endl;

    return 0;
}
