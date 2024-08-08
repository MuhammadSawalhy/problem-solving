// ﷽
// https://codeforces.com/group/Rilx5irOux/contest/538817/problem/J

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

vector<int> one(const vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);

    for (int i = 0, cur = 0; i < n; i++) {
        cur = max({a[i], cur + a[i], 0ll});
        ans[i] = cur;
    }

    return ans;
}

vector<int> two(const vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);

    for (int i = 0, ps = 0, mnps = 1e18, mnmn = 1e18, mx = 0; i < n; i++) {
        minit(mnmn, mnps + a[i]);
        ps += a[i];
        maxit(mx, a[i]);
        minit(mnps, ps - mx);
        if (i > 0)
            maxit(ans[i], ps - mnmn);
    }

    return ans;
}

vector<int> three(const vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);

    for (int i = 0, ps = 0, mnps = 0, mnmn = 1e18, mx = 0; i < n; i++) {
        minit(mnmn, mnps + a[i]);
        ps += a[i];
        minit(mnps, ps);
        if (i > 0)
            maxit(ans[i], mx + a[i]);
        maxit(mx, ps - mnmn);
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &x: a) cin >> x;

    vector<int> ans(n), ans1 = one(a), ans2 = two(a), ans3 = three(a);

    debug(ans3);

    for (int i = 0; i < n; i++) maxit(ans[i], ans1[i], ans2[i], ans3[i]);
    for (int i = 1; i < n; i++) maxit(ans[i], ans[i - 1]);

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
