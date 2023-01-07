// Date: 31-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int m;
string needle, haystash;
bool first = true;

void solve() {
    int n = haystash.length();
    int table[m];
    table[0] = 0;

    int i, k;
    for (i = 1, k = 0; i < m; i++) {
        while (k > 0 && needle[k] != needle[i])
            k = table[k - 1];
        k += needle[i] == needle[k];
        table[i] = k;
    }

    bool emptyline = false;
    for (i = 0, k = 0; i < n; i++) {
        while (k > 0 && needle[k] != haystash[i])
            k = table[k - 1];

        k += needle[k] == haystash[i];

        if (k == m) {
            if (!first && !emptyline) cout << endl, emptyline = true;
            k = table[k - 1];
            cout << i - m + 1 << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> m >> needle >> haystash) {
        solve();
        first = false;
    }
        
    return 0;
}
