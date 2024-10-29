// ﷽
// https://codeforces.com/contest/2035/problem/B

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

    if (n == 1 || n == 3) {
        cout << "-1\n";
        return;
    }

    if (n & 1 ^ 1) {
        string s(n, '3');
        s[n - 1] = s[n - 2] = '6';
        cout << s << '\n';
        return;
    }

    string s(n, '3');
    s[n - 1] = s[n - 2] = s[n - 4] = '6';
    cout << s << endl;
    //  30306
    // 30306
    //
    // 333366
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
