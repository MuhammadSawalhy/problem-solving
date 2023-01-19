// ﷽
#include <bits/stdc++.h>

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

    string s, p;
    cin >> s >> p;

    s = p + "|" + s;
    int n = (int) s.length();
    int table[n];
    table[0] = 0;

    /* memset(table, 0, sizeof table); */

    // dde|abcddefddfe
    // 010000031002100
    for (int l = 1, r = 0; l < n; l++) {
        if (l > r) {
            r = l;
            while (r < n && s[r - l] == s[r]) r++;
            table[l] = r - l;
        } else {
            table[l] = table[r - l];
            if (table[l] == r - l) {
                while (r < n && s[r - l] == s[r]) r++;
                table[l] = r - l;
            }
        }
    }

    cout << count(table, table + n, p.length());

    return 0;
}
