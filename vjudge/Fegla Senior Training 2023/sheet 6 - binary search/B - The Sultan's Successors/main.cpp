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

    int k;
    cin >> k;

    int chess[8][8];
    bool dia[2][20];

    while (k--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> chess[i][j];
        int row[8];
        iota(row, row + 8, 0);

        int ans = 0;
        do {
            bool ok = true;
            for (int i = 0; i < 20; i++)
                dia[0][i] = dia[1][i] = 0;
            for (int i = 0; i < 8; i++) {
                ok &= dia[0][i + row[i]] == 0 && dia[1][i - row[i] + 7] == 0;
                dia[0][i + row[i]] = dia[1][i - row[i] + 7] = 1;
            }

            if (!ok) continue;
            int val = 0;
            for (int col = 0; col < 8; col++)
                val += chess[row[col]][col];
            ans = max(ans, val);
        } while (next_permutation(row, row + 8));

        cout << setw(5) << right << ans << '\n';
    }


    return 0;
}
