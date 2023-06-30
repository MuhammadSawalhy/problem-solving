// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    int val[n + 1], cnt = 0;
    val[0] = 0;

    s = "*" + s;

    for (int i = 1; i <= n; i++) {
        val[i] = val[i - 1];
        if (s[i] == '(') {
            val[i]++;
        } else {
            val[i]--;
        }

        if (val[i] < 0) {
            cout << -1 << endl;
            exit(0);
        }

        if (s[i] == '#') {
            cnt++;
        }
    }

    int mn = 1e18, j = cnt - 1;
    vector<int> ans(cnt, 1);

    for (int i = n; i > 0 && val[n] > 0 && mn > 0; i--) {
        mn = min(mn, val[i]);
        if (s[i] != '#') continue;
        int x = min(mn, val[n]);
        val[n] -= x;
        mn -= x;
        ans[j--] += x;
    }

    if (val[n] > 0) {
        cout << -1 << endl;
        exit(0);
    }

    for (int i = 0; i < cnt; i++)
        cout << ans[i] << endl;

    return 0;
}
