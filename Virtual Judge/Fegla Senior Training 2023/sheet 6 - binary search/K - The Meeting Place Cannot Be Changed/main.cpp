// ﷽
#include <bits/stdc++.h>

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

    int n;
    cin >> n;

    int x[n], v[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < n; i++)
        cin >> v[i];


    auto check =  [&](double time) -> bool {
        double l = 0, r = 1e9;
        for (int i = 0; i < n; i++) {
            l = max(l, x[i] - 1LL * v[i] * time);
            r = min(r, x[i] + 1LL * v[i] * time);
        }
        return l <= r;
    };

    double s = 0, e = 2e9;
    while (e - s > 1e-9) {
        double m = (e + s) / 2;
        if (check(m)) {
            e = m;
        } else {
            s = m;
        }
    }

    cout << fixed << setprecision(14) << e << endl;


    return 0;
}
