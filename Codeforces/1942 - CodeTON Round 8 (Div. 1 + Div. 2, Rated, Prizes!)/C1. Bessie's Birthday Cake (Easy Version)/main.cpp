// ﷽
// https://codeforces.com/contest/1942/problem/C1

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a;
    for (int i = 0; i < x; i++) {
        int x;
        cin >> x, x--;
        a.push_back(x);
    }

    sort(all(a));
    int ans = x - 2;

    debug(a);
    for (int i = 1; i < x; i++) {
        if (a[i] - a[i - 1] == 2) ans++;
    }

    if (a[0] == 0 && a[x - 1] == n - 2) ans++;
    if (a[0] == 1 && a[x - 1] == n - 1) ans++;

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
