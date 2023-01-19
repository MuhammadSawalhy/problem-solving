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
    int n = s.length();
    int z[n];
    z[0] = 0;

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        z[i] = 0;
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            r = i + z[i], l = i;
    }

    debug_itr(z, n);

    cout << count(z, z + n, p.length());

    return 0;
}
