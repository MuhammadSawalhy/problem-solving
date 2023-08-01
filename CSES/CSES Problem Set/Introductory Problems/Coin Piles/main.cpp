// Date: 02-01-2023
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

    // let a = 2x + (n-x) = n + x
    // ->  b = x + 2(n-x) = 2n - x
    // ->  a + b = 3 n
    // ->  assume a <= b
    // ->  n >= 1 && x >= 0
    //
    // check if == 0 mod 3, but (a, b) = (1, 8) doesn't work

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if ((a+b) % 3 == 0 && min(a,b) - (a+b)/3 >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
