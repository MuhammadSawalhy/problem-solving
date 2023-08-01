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

    // we need the sum itself to be divisible by 2
    // sum = (n) * (n + 1) / 2
    if (n % 4 != 0 && (n + 1) % 4 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    ll sum = (ll)n * (n + 1) / 4;

    int i = 0, j = 0;
    int f[n], s[n];

    // greedy approach is correct as long as you have all numbers from 1 to n
    // and this is our case
    for (int x = n; x >= 1; x--) {
        if (x > sum) {
            s[j++] = x;
            continue;
        }
        f[i++] = x;
        sum -= x;
    }

    assert(sum == 0);

    cout << "YES" << endl;
    cout << i << endl;
    for (int k = 0; k < i; k++)
        cout << f[k] << " \n"[k == i - 1];
    cout << j << endl;
    for (int k = 0; k < j; k++)
        cout << s[k] << " \n"[k == j - 1];

    return 0;
}
