// ﷽
// https://codeforces.com/contest/2053/problem/B

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
    int n;
    cin >> n;

    vi ps(2 * n + 5);
    int l[n], r[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] == r[i]) {
            ps[l[i]]++;
        }
    }

    auto ps2 = ps;
    for (int i = 1; i <= 2 * n; i++) {
        ps[i] = ps[i] == 0;
        ps[i] += ps[i - 1];
    }

    string s(n, '0');
    for (int i = 0; i < n; i++) {
        int sum = ps[r[i]] - ps[l[i] - 1] + (l[i] == r[i] && ps2[l[i]] == 1);
        debug(i, sum);
        if (sum) {
            s[i] = '1';
        }
    }
    cout << s << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
