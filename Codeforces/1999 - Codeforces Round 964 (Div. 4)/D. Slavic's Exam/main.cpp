// ﷽
// https://codeforces.com/contest/1999/problem/D

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = sz(s), m = sz(t);
    debug(s, t);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && (s[i] == t[j] || s[i] == '?')) {
            s[i] = t[j];
            j++;
            continue;
        }

        if (s[i] == '?') s[i] = 'a';
    }


    if (j < m) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << s << endl;
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