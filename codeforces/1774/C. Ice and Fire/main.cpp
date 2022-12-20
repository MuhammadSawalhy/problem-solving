// Date: 17-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;

    int ones = 0, zeros = 0;
    bool one = false, zero = false;
    for (int i = 2; i <= n; i++) {
        if (s[i - 2] == '1')
            ones++, zeros = 0, one |= true;
        else
            zeros++, ones = 0, zero |= true;
        if (one && zeros) {
            cout << i - zeros << " ";
        } else if (zero && ones) {
            cout << i - ones << " ";
        } else {
            cout << "1 ";
        }
    }

    cout << endl;
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
