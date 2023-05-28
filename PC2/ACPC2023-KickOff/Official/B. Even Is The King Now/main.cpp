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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int minodd = 1e9 + 1;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] & 1) {
            minodd = min(minodd, a[i]);
        }
    }

    if (sum & 1) {
        sum -= minodd;
    }

    if (sum == 0)
        sum = -1;

    cout << sum;

    return 0;
}
