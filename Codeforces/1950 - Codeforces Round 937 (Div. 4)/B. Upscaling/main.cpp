// ﷽
// https://codeforces.com/contest/1950/problem/B

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
    int n;
    cin >> n;

    vector<string> ans(2 * n, string(2 * n, ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                for (int r = 0; r < 2; r++) {
                    if ((j + i) & 1) {
                        ans[2 * i + k][2 * j + r] = '.';
                    } else {
                        ans[2 * i + k][2 * j + r] = '#';
                    }
                }
            }
        }
    }

    for (auto&s : ans) cout << s << endl;
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
