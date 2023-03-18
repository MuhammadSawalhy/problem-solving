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

// n == 1 ---> x x         ---> any value
// n == 2 ---> x x x x     ---> twos or zeros
// n == 3 ---> x x x x x x ---> NOT VALID
// n == 3 ---> x x x x x x ---> NOT VALID

bool valid(vector<int> v) {
    int cnt = v.size();
    bool ok = true;
    for (int i = 0; i < 1 << cnt; i++) {
        if (__builtin_popcount(i) != cnt / 2) continue;
        int s = 0, p = 1;
        for (int j = 0; j < cnt; j++) {
            if (i >> j & 1) {
                s += v[j];
            } else {
                p *= v[j];
            }
        }
        ok &= p == s;
    }
    return ok;
}


int x = 8;
vector<int> v(4);
void dfs(int cnt = 0) {
    return;
    if (v.size() == cnt) {
        if (valid(v)) {
            for (auto i: v)
                cout << i << " ";
            cout << endl;
        }
        return;
    }
    for (int i = (cnt == 0 ? -x : v[cnt - 1]); i <= x; i++) {
        v[cnt] = i;
        dfs(cnt + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    ll a[n * 2];
    for (int i = 0; i < n * 2; i++) cin >> a[i];
    if (n == 1) {
        cout << abs(a[0] - a[1]) << endl;
        return;
    }

    sort(a, a + n * 2);

    if (n == 2) {
        vector<vector<int>> twos = {
                {-1, -1, -1, 2},
                {0, 0, 0, 0},
                {2, 2, 2, 2},
        };

        long long ans = 1e18;
        for (auto v: twos) {
            long long x = 0;
            for (int i = 0; i < n * 2; i++) {
                x += abs(a[i] - v[i]);
            }
            ans = min(ans, x);
        }
        cout << ans << endl;

        return;
    }

    long long ans = 0, x = 0;
    for (int i = 0; i < n * 2; i++)
        ans += abs(a[i]);
    for (int i = 0; i < n * 2 - 1; i++)
        x += abs(a[i] + 1);
    x += abs(a[2 * n - 1] - n);

    if (n & 1)
        cout << ans << endl;
    else
        cout << min(ans, x) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    dfs();

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
