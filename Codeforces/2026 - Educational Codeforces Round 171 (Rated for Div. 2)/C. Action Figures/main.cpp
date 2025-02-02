// ﷽
// https://codeforces.com/contest/2026/problem/C

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
    string s;
    cin >> s;

    int ans = 0;

    debug(s);
    for (int i = 0, j = n - 1; i <= j; j--) {
        debug(i, j);

        if (i == j) {
            ans += i + 1;
            break;
        }
        if (s[j] == '1') {
            ans += i + 1;
            i++;
        } else {
            ans += j + 1;
            if (i > 0) {
                i--;
                ans -= i + 1;
            }
        }
    }


    cout << ans << endl;
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
