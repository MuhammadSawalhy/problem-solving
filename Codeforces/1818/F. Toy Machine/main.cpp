// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    n-=2;

    if (k - 1 == n / 2) {
        cout << "DL\n";
        return 0;
    }

    if (k - 1< n / 2) {
        while (k--)
            cout << "DRUL";
        cout << '\n';
        return 0;
    }

    // Put it top right
    for (int i = 0; i < n - k + 1; i++)
        cout << "DLUR";

    // Put all to the right
    for (int i = 0; i < n; i++)
        cout << "DRUR";

    // Move to the top left cell (last step)
    cout << "LDR";

    for (int i = 0; i < n / 2; i++)
        cout << "ULDR";

    cout << "L\n";

    return 0;
}
