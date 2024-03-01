// ﷽
// https://codeforces.com/contest/1923/problem/B

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    int i = 0, j;
    while (i < n && a[i].first < 0) i++;
    j = i--;

    // (i) me (j)

    debug(a);
    int time = 0, power = k;
    while (i > -1 || j < n) {
        int I = 1e9, J = 1e9;
        if (i > -1) I = -a[i].first;
        if (j < n) J = a[j].first;

        debug(i, j);
        if (I < J) {
            if (time >= -a[i].first) {
                cout << "NO\n";
                return;
            }
            int fired = min(power, a[i].second);
            a[i].second -= fired;
            power -= fired;
            i -= a[i].second == 0;
        } else {
            if (time >= a[j].first) {
                cout << "NO\n";
                return;
            }
            int fired = min(power, a[j].second);
            a[j].second -= fired;
            power -= fired;
            j += a[j].second == 0;
        }

        if (power == 0) {
            power = k;
            time++;
        }
    }

    cout << "YES\n";
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
