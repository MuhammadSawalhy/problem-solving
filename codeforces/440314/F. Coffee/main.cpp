// ﷽
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

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt += 2;
            ans += 1;
            cnt = min(cnt, 2ll);
        } else {
            if (cnt) {
                ans += 1;
                cnt -= 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
