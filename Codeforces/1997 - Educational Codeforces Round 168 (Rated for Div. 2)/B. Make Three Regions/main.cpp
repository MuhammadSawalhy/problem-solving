// ﷽
// https://codeforces.com/contest/1997/problem/B

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
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s >> t;
    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
        ans += (s[i - 1] == '.' && s[i + 1] == '.' && s[i] == '.' && t[i - 1] == 'x' && t[i + 1] == 'x' && t[i] == '.');
    }

    swap(s, t);

    for (int i = 1; i < n - 1; i++) {
        ans += (s[i - 1] == '.' && s[i + 1] == '.' && s[i] == '.' && t[i - 1] == 'x' && t[i + 1] == 'x' && t[i] == '.');
    }

    cout << ans << endl;
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
