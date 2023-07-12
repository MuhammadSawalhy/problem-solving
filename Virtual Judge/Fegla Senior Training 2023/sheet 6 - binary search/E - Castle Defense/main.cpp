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

const int N = 5e5 + 5;
int n, r, k;
ll a[N], ps[N];

bool check(ll x) {
    queue<pair<int, int>> qu;

    ll s = 0;
    int K = k;
    for (int i = 1; i <= n; i++) {
        while (qu.size() && qu.front().first < i) s -= qu.front().second, qu.pop();
        if (ps[i] + s >= x) continue;
        if (ps[i] + s < x && x - ps[i] - s <= K) {
            int d = x - ps[i] - s;
            qu.push({ i + 2 * r, d });
            K -= d;
            s += d;
        }  else {
            return false;
        }
    }

    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> r >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i], ps[max(1LL, i - r)] += a[i], ps[min(n + 1, i + r + 1)] -= a[i];

    for (int i = 1; i <= n; i++)
        ps[i] += ps[i - 1];

    debug_itr(ps, n + 1);

    ll s = 0, e = 2e18;
    while (e - s > 1) {
        ll m = (s + e) / 2;
        if (check(m)) {
            s = m;
        } else {
            e = m;
        }
    }

    cout << s << endl;

    return 0;
}
