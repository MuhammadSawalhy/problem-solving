// ﷽
// https://codeforces.com/contest/2055/problem/C

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[i] += a[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col[j] += a[i][j];
        }
    }

    int i = 0, j = 0;
    for (auto c: s) {
        if (c == 'R') {
            a[i][j] = -col[j];
            row[i] += a[i][j];
            j++;
        } else {
            a[i][j] = -row[i];
            col[j] += a[i][j];
            i++;
        }
    }
    assert(i == n - 1);
    assert(j == m - 1);
    assert(row[i] == col[j]);

    a[i][j] = -row[i];
    for (int i =0 ; i<  n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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
