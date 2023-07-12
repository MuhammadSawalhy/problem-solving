// ﷽
#include <map>
#include <cmath>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <assert.h>
#include <iostream>
#include <algorithm>

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
    int n, k;
    string s;
    cin >> n >> k >> s;

    int l[26], u[26];
    for (int c = 0; c < 26; c++)
        l[c] = u[c] = 0;

    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            l[s[i] - 'a']++;
        } else {
            u[s[i] - 'A']++;
        }
    }

    int ans = 0;
    for (int c = 0; c < 26; c++) {
        ans += min(l[c], u[c]);
        int a = min(k, abs(l[c] - u[c]) / 2);
        k -= a;
        ans += a;
    }

    cout << ans << endl;
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
