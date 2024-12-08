// ﷽
// https://toph.co/p/patterns-of-coffee-type

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, p;
    cin >> n >> p;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
    }

    int cnt[p], last[p];
    double ans[p];
    for (int i = 0; i < p; i++) ans[i] = 0, cnt[i] = 0, last[i] = -1;

    for (int i = 0; i < n; i++) {
        debug(i, last[a[i]]);
        if (~last[a[i]] && i > last[a[i]] + 1) {
            cnt[a[i]]++;
            ans[a[i]] += (i - last[a[i]] - 1);
        }
        last[a[i]] = i;
    }

    bool found = false;
    for (int i = 0; i < p; i++) {
        if (cnt[i])
            cout << i + 1 << ' ' << ans[i] / cnt[i] << '\n', found = true;
    }

    if (!found) {
        cout << "No Pattern\n";
        return;
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(2);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        cout << "Test Case: " << t << '\n';
        solve();
    }

    return 0;
}
