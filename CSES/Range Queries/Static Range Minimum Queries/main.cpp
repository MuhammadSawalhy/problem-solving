// ﷽
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

constexpr int N = 2e5, LOG = 32 - __builtin_clz(2e5);
int sp[N][LOG], n, q;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> sp[i][0];

    for (int l = 1; l < LOG; l++)
        for (int i = 0; i + (1 << l) <= n; i++)
            sp[i][l] = min(sp[i][l - 1], sp[i + (1 << (l - 1))][l - 1]);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = b - a + 1;
        l = 31 - __builtin_clz(l);
        cout << min(sp[a][l], sp[b - (1 << l) + 1][l]) << endl;
    }

    return 0;
}
