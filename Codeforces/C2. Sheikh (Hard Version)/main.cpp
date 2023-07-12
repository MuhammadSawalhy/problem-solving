// ﷽
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

const int N = 2e5;

int n, q;
long long sum[N + 1], xr[N + 1];

long long calc(int i, int j) {
    if (i < 1 || j > n || i > j) return -1;
    return sum[j] - sum[i - 1] - (xr[j] ^ xr[i - 1]);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> q;
        int a[n + 2];
        sum[0] = 0, xr[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum[i] = sum[i - 1] + a[i], xr[i] = xr[i - 1] ^ a[i];

        int prev[n + 1], next[n + 1];
        prev[1] = 0, next[n] = n + 1;

        for (int i = 2; i <= n; i++) {
            if (a[i - 1] == 0) prev[i] = prev[i - 1];
            else prev[i] = i - 1;
        }

        for (int i = n - 1; ~i; i--) {
            if (a[i + 1] == 0) next[i] = next[i + 1];
            else next[i] = i + 1;
        }

        while (q--) {
            int mn = 1e9, ll, rr, l, r, jj, i, j;
            cin >> l >> r, i = l, j = r;

            long long f = calc(i, j);

            while (i < j && calc(i, jj = max(prev[j], i)) == f) j = jj;
            mn = j - i, ll = i, rr = j;

            i = next[i];
            for (; i <= j; i = next[i]) {
                while (j < r && calc(i, j) != f) j = min(next[j], r);
                if (calc(i, j) != f) break;
                if (j - i < mn)
                    mn = j - i, ll = i, rr = j;
            }

            cout << ll << " " << rr << endl;
        }
    }
    
    return 0;
}

