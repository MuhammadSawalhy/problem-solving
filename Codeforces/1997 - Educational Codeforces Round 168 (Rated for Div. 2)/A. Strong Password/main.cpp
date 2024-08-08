// ﷽
// https://codeforces.com/contest/1997/problem/0

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

    int n = sz(s);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            // insert here
            cout << s.substr(0, i) + (s[i] == 'a' ? 'b' : 'a') + s.substr(i) << endl;
            return;
        }
    }

    cout << s + (s.back() == 'a' ? 'b' : 'a') << endl;
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
