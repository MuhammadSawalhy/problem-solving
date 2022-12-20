// Date: 12-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int n;
    string s;
    cin >> n >> s;

    bool ok = false;
    map<pair<char, char>, bool> found;
    for (int i = 2; i < n - 1; i++) {
        found[{s[i - 2], s[i - 1]}] = true;
        if (found[{s[i], s[i + 1]}])
            ok = true;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
