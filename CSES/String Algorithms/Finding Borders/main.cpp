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

    for (int i = n - 1; ~i; i--) {
        if (z[i] == n - i)
            cout << n - i << " ";
    }

    return 0;
}
