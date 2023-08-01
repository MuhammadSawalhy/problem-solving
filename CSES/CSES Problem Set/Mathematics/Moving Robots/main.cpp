// ﷽
#include <bits/stdc++.h>

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

    int k;
    cin >> k;

    vector<vector<long double>> chess(8, vector<long double>(8, 1));

    while (k--) {
        vector<vector<long double>> ch(8, vector<long double>(8, 0));
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++) {
                int cnt = 2 + (i > 0 && i < 7) + (j > 0 && j < 7), c = 0;
                if (i > 0)
                    ch[i - 1][j] += chess[i][j] / cnt, c++;
                if (i < 7)
                    ch[i + 1][j] += chess[i][j] / cnt, c++;
                if (j > 0)
                    ch[i][j - 1] += chess[i][j] / cnt, c++;
                if (j < 7)
                    ch[i][j + 1] += chess[i][j] / cnt, c++;
                assert(cnt == c);
            }
        chess = ch;
    }

    long double ans = 0;

    cout << ans;

    return 0;
}
