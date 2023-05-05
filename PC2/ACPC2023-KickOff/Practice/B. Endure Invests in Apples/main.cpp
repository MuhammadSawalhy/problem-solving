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
    int x, y;
    cin >> n >> x >> y;

    int a[n];
    int ans[3]{};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= x)
            ans[0]++;
        else if (a[i] <= y)
            ans[1]++;
        else
            ans[2]++;
    }


    for (auto i: ans)
        cout << i << ' ';

    return 0;
}
