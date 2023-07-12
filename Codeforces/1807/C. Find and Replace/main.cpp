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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> b(200, -1);

    b[s[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (b[s[i]] == -1) {
            b[s[i]] = b[s[i - 1]] ^ 1;
        }
        if (b[s[i]] == b[s[i - 1]]) {
            return cout << "NO\n", void();
        }
    }

    cout << "YES\n";
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
