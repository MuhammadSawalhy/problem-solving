// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int q, n, k;

int solve() {
    int start = 1, end = n, step = 1;
    int cnt = 0;
    while (true) {
        if (start == end) {
            assert(k == n);
            return start;
        }

        int y = (end - start - step) / (2 * step);
        int last_removed = start + step + 2 * y * step;
        int prev = cnt;
        cnt += (end - start + 2 * step - 1) / (2 * step);

        if (cnt >= k) {
            k -= prev;
            return start + step + (k - 1) * 2 * step;
        }

        if (last_removed != end) {
            // remove first
            cnt++;
            if (k == cnt) return start;
            start += step * 2;
        } else {
            end -= step;
        }

        step *= 2;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> q;
    while (q--) {
        cin >> n >> k;
        cout << solve() << endl;
    }

    return 0;
}
