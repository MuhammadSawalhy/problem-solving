// ﷽
// https://csacademy.com/ieeextreme18/task/doubled-sequence/

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
    vi perm(n * 2);

    for (int i = 0; i < 2 * n; i += 2) {
        perm[i] = perm[i + 1] = i / 2 + 1;
    }

    do {
        vi perv(n + 1, -1);

        bool ok = true;
        for (int i = 0; i < n * 2; i++) {
            if (perv[perm[i]] != -1) {
                ok &= (i - perv[perm[i]]) == perm[i];
            } else {
                perv[perm[i]] = i;
            }
        }

        perv = vector<int>(n + 1, -1);

        if (ok) {
            for (int i = 0; i < 2 * n; i++) {
                cout << perm[i] << ' ';
            }

            string ss(2 * n, ' ');
            for (int i = 0; i < 2 * n; i++) {
                if (perv[perm[i]] != -1) {
                    ss[i] = ')';
                } else {
                    perv[perm[i]] = i;
                    ss[i] = '(';
                }
            }
            cout << endl;

            cout << ss << endl;
        }
    } while (next_permutation(all(perm)));

    cout << -1 << endl;
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
