// ﷽
// https://codeforces.com/contest/2048/problem/C

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
    string s;
    cin >> s;

    int n = s.size();
    vector<int> ind[n + 1];
    bitset<5000> bs(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int l = n - i;
            int mxcnt = 0;
            int ind = -1;
            for (int j = 0; j + l <= n; j++) {
                if (s[j] == '1') {
                    int cnt = 0;
                    for (int k = 0; k < l; k++) {
                        if (s[i + k] != s[j + k]) cnt++;
                        else break;
                    }
                    if (cnt > mxcnt) {
                        mxcnt = cnt;
                        ind = j;
                    }
                }
            }

            cout << 1 << ' ' << n << ' ' << ind + 1 << ' ' << ind + l << endl;
            return;
        }
    }

    assert(s == string(n, '1'));
    cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << endl;
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
