// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <assert.h>

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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ones = 0;
    int groups = 0;

    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ok = true;
            ones++;
        } else {
            groups += ok;
            ok = false;
        }
    }

    groups += ok;

    if ((ones & 1) || (groups == 1 && n == 3)) {
        cout << -1 << endl;
    } else {
        if (groups == 1 && ones == 2) {
            if (n == 4 && s[0] == '0' && s[n - 1] == '0')
                cout << 3 << endl;
            else
                cout << 2 << endl;
        } else {
            cout << ones / 2 << endl;
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
