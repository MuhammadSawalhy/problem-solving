// ﷽
// https://codeforces.com/contest/2049/problem/A

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
    vector<int> a(n);
    int zeros = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        zeros += a[i] == 0;
    }

    if (zeros == n) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int inside = 0;
            int outside = 0;
            for (int k = 0; k < i; k++) {
                outside += a[k] == 0;
            }
            for (int k = i; k <= j; k++) {
                inside += a[k] == 0;
            }
            for (int k = j + 1; k < n; k++) {
                outside += a[k] == 0;
            }

            if (outside == n - (j - i + 1) && inside == 0) {
                cout << 1 << endl;
                return;
            }
        }
    }

    cout << 2 << endl;
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
