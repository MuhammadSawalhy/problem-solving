#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1)
            odds++;
        else
            evens++;
    }

    if (min(odds, evens) & 1) {
        cout << "Odd\n";
    } else {
        cout << "Even\n";
    }

    return 0;
}
