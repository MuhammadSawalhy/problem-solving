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

    string s;
    cin >> s;

    int n = s.length(), z[n + 1];
    memset(z, 0, sizeof z);

    for (int i = 1, l = 1, r = 1; i < n; i++) {
        if (i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) r = i + z[i], l = i;
    }
    
    int ans[n], c = 0;
    debug_itr(z, n);

    z[n] = 0;
    for (int i = 0; i <= n; i++) {
        if (z[i] + i == n) ans[c++] = i;
    }

    for (int i = 0; i < c; i++)
        cout << ans[i] << " ";

    return 0;
}
