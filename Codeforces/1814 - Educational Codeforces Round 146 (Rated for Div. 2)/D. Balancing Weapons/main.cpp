// ﷽
// https://codeforces.com/contest/1814/problem/D

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

const int N = 3003;
int n, k;
int f[N], d[N];
vector<int> a;

int solve(int x) {
    int ans = n;
    int inside = 0;
    vector<int> fr(n);

    auto add = [&](int i) {
        inside += !fr[i]++;
    };

    auto remove = [&](int i) {
        inside -= !--fr[i];
    };

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        int d = (x - k + f[i] - 1) / f[i];
        if (!d) d++;
        while (f[i] * d <= x + k) {
            points.push_back({f[i] * d, i});
            d += max(1ll, k / f[i]);
        }
    }

    sort(all(points));
    debug(x, points);

    int I = 0, J;
    while (I < n && a[I] < points.front().first) I++;
    J = I;
    int j = 0;

    for (int i = 0; i < (int) points.size(); i++) {
        j = max(j, i);
        int end = points[i].first + k;

        while (J < n && a[J] <= end) {
            J++;
        }

        while (I < J && a[I] < points[i].first) {
            I++;
        }

        while (j < (int) points.size() && points[j].first <= end) {
            add(points[j++].second);
        }

        debug(I, J, inside);

        if (inside == n)
            minit(ans, inside - (J - I));

        remove(points[i].second);
    }

    debug(ans);
    return ans;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    debug(n, k);
    int ans = n;

    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = f[i] * d[i];
    sort(all(a));

    for (int i = 0; i < n; i++)
        minit(ans, solve(f[i] * d[i]));

    cout << ans << '\n';
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
