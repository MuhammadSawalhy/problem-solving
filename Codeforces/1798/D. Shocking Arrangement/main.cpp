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

void solve() {
    int n;
    cin >> n;
    ll a[n];
    bool pos = false, neg = false;
    for (int i = 0; i < n; i++) cin >> a[i], pos |= a[i] > 0, neg |= a[i] < 0;

    if (!neg && !pos) {
        cout << "NO" << endl;
        return;
    }

    sort(a, a + n);

    int i = 0, j = n - 1, k = 0;
    long long s = 0;
    long long ps[n];
    while (k < n) {
        if (a[i] <= 0 && s + a[i] >= a[0]) {
            s += a[i++];
            ps[k++] = s;
        } else if (s + a[j] < a[n - 1]) {
            s += a[j--];
            ps[k++] = s;
        } else {
            debug_itr(a, a + n);
            debug(i, j, s);
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    // cout << ps[0] << ' ';
    // for (int i = 1; i < n; i++)
    //     cout << ps[i] - ps[i - 1] << " ";
    // cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
