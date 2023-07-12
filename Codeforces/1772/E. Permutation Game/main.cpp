// Date: 18-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
    int n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a, a + n);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += b[i] != a[i];
    }

    if (cnt <= 2) {
        cout << "First" << endl;
        return;
    }

    reverse(a, a + n);
    cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += b[i] != a[i];
    }

    if (cnt <= 2) {
        cout << "Second" << endl;
        return;
    }

    cout << "Tie" << endl;
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
