// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];

    long long s = 0, e = 1e18;

    while (e - s > 1) {
        long long mid = (s + e) / 2;
        int cnt = k - 1;
        long long sum = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (sum > mid) ok = false;
            if (cnt && sum + x[i] > mid) {
                sum = x[i];
                cnt--;
            } else {
                sum += x[i];
            }
        }

        if (sum <= mid && ok) e = mid;
        else s = mid;
    }

    cout << e << endl;

    return 0;
}
