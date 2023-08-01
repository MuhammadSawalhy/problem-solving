// Date: 01-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    s += ' ';
    int n = s.length();


    int cnt = 0, c = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (c == s[i]) {
            cnt++;
        } else {
            ans = max(cnt, ans);
            c = s[i];
            cnt = 1;
        }
    }

    cout << ans << endl;

    return 0;
}
