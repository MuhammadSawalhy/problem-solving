// ﷽
// https://vjudge.net/contest/652187#problem/R

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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int N = 150'000 + 5;
constexpr int LG = __lg(N) + 1;
int nxt[N][LG];

void solve() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> a(n), ps(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i] = a[i];
        if (i > 0) ps[i] += ps[i - 1];
    }

    for (int i = 0; i < n; i++) {
        nxt[i][0] = upper_bound(ps.begin(), ps.end(), (i ? ps[i - 1] : 0) + s) - ps.begin();
    }

    for (int l = 1; l < LG; l++) {
        for (int i = 0; i < n; i++) {
            if (nxt[i][l - 1] < n)
                nxt[i][l] = nxt[nxt[i][l - 1]][l - 1];
            else
                nxt[i][l] = n;
            debug(i, l, nxt[i][l]);
        }
    }

    debug(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int kk = k;
        while (j < n && kk > 0) {
            int l = __lg(kk);
            j = nxt[j][l];
            kk -= (1 << l);
            ans = max(ans, j - i);
            debug(i, j, l, kk, ans);
        }
    }
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
