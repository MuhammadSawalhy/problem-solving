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

    int n;
    cin >> n;

    while (n >= 1) {
        cout << n << " ";
        if (n == 1) break;
        if (n & 1)
            n = n * 3 + 1;
        else
            n /= 2;
    }

    return 0;
}
