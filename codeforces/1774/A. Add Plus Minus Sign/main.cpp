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
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool sign = 1;
    if (s[0] == '1')
        sign = !sign;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            if (sign)
                cout << "+";
            else
                cout << "-";
            sign = !sign;
        } else
            cout << "+";
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

