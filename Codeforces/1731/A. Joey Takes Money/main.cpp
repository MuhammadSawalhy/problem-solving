// Date: 27-12-2022
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
    ll a[n];
    ll s  = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s *= a[i];
    }


    cout << 2022LL * (s + (n - 1) ) << endl;
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
