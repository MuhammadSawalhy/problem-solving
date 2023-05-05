// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 1e6 + 1;
vector<vector<int>> facts(N);
vector<int> fr(N);
vector<bool> done(N);
vector<int> val(N);
int inc = 0;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    inc++;
    for (int i = 0; i < n; i++) cin >> a[i], fr[a[i]] = 0, done[a[i]] = false, val[a[i]] = inc;

    for (int i = 0; i < n; i++) {
        fr[a[i]]++;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (done[a[i]]) continue;
        done[a[i]] = true;
        ans += 1LL * (fr[a[i]]) * (fr[a[i]] - 1) * (fr[a[i]] - 2);
    }

    for (int i = 0; i < n; i++) {
        for (auto f: facts[a[i]]) {
            if (a[i] * f < N && val[a[i] / f] == inc && val[a[i] * f] == inc)
                ans += fr[a[i] / f] * fr[a[i] * f];
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            facts[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
