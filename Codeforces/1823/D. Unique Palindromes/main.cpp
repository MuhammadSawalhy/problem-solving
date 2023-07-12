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

string abc;

void solve() {
    int n, k;
    cin >> n >> k;

    int x[k], c[k];
    for (int i = 0; i < k; i++) cin >> x[i];
    for (int i = 0; i < k; i++) cin >> c[i];

    if (c[0] > x[0]) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i < k; i++) {
        if (x[i] - x[i - 1] < c[i] - c[i - 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    int j = 0;
    string ans = string(c[0] - 3, 'a') + abc.substr(j, x[0] - (c[0] - 3));
    j += x[0] - (c[0] - 3);

    char ch = 'd';
    for (int i = 1; i < k; i++) {
        ans += string(c[i] - c[i - 1], ch) + abc.substr(j, (x[i] - x[i - 1]) - (c[i] - c[i - 1]));
        j += (x[i] - x[i - 1]) - (c[i] - c[i - 1]);
        ch++;
    }

    ans += abc.substr(0, n - x[k - 1]);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 1e6; i++) {
        abc += 'a' + (i % 3);
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
