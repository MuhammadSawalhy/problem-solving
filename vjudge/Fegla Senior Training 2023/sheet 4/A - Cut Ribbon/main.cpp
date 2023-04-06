// ﷽
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, a, b, c;

    cin >> n >> a >> b >> c;

    int ans = 0;
    for (int i = 0; i <= n / a; i++) {
        for (int j = 0; j <= (n - i * a) / b; j++) {
            int k = (n - i * a - j * b) / c;
            if (i * a + j * b + k * c == n) {
                ans = max(ans, i + j + k);
            }
        }
    }

    cout << ans;

    return 0;
}
