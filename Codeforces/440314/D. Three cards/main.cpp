// ﷽
// ﷽
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

    int a, b;
    cin >> a >> b;

    if (a < b) swap(a, b);

    if (a % b == 0) {
        int x = a / b;

        if (x == 2)
            cout << a / 3 << endl;
        else
            cout << a / 2 << endl;

    } else {
        cout << b * 3 << endl;
    }


    return 0;
}
