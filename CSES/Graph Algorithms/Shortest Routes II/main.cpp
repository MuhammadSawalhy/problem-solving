// ﷽
#include <bits/stdc++.h>
#include <climits>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    const long long inf = 1e17;
    long long mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) mat[i][j] = inf;
        mat[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        mat[a][b] = min(mat[a][b], c);
        mat[b][a] = min(mat[b][a], c);
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (mat[a][b] == inf)
            mat[a][b] = -1;
        cout << mat[a][b] << endl;
    }

    return 0;
}
