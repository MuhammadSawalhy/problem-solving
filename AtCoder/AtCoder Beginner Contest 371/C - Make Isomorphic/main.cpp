// ﷽
// https://atcoder.jp/contests/abc371/tasks/abc371_c

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, mg;
    cin >> n >> mg;

    vvi madj(n, vi(n));

    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        madj[u][v] = 1;
        madj[v][u] = 1;
    }

    int mh;
    cin >> mh;
    vvi hadj(n, vi(n));

    for (int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        hadj[u][v] = 1;
        hadj[v][u] = 1;
    }

    vector<int> perm(n);
    iota(all(perm), 0);

    vvi A(n, vi(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    debug(A.front());
    debug(A[n - 2]);

    int cost = 1e18;
    do {
        debug(perm);
        int cur = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (madj[i][j] != hadj[perm[i]][perm[j]]) {
                    debug(madj[i][j], hadj[perm[i]][perm[j]]);
                    debug(i, j, A[perm[i]][perm[j]]);
                    cur += A[perm[i]][perm[j]];
                }
            }
        }
        debug(cur);

        minit(cost, cur);
    } while (next_permutation(all(perm)));

    cout << cost << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
