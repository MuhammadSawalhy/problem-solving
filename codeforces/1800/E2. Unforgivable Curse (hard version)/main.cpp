// ﷽
#include <map>
#include <cmath>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <assert.h>
#include <iostream>
#include <string.h>
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
    string s, t;
    cin >> n >> k >> s >> t;

    int fr[26];

    memset(fr, 0, sizeof fr);

    for (int i = 0; i < n; i++) {
        fr[s[i] - 'a']++;
        fr[t[i] - 'a']--;
    }

    for (int c = 0; c < 26; c++) {
        if (fr[c] != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    int mx = 0;
    while (mx + k + 1 <= n - 1 && mx < k)
        mx++;

    if (mx == k) {
        cout << "YES" << endl;
        return;
    }
    
    debug(s, t);
    for (int i = 0; i < n; i++) {
        if (i % k > mx) {
            debug(t[i], s[i]);
            if (t[i] != s[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
