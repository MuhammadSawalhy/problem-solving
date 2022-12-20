// Date: 18-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int k, n;
    cin >> k >> n;
    int d = 0;
    int last = 1;
    cout << 1 << " ";
    for (int i = 1; i < k; i++) {
        int rem = k - i; // 6 - 
        d++;
        if (rem - 1 > n - (last + d))
            d = 1;
        last = last + d;
        cout << last << " ";
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
