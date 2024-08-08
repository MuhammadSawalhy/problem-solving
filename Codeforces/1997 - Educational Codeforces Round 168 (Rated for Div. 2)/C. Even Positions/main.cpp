// ﷽
// https://codeforces.com/contest/1997/problem/C

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
    string s;
    cin >> n >> s;

    for (int i = 0, x = 0; i < n; i += 2) {
        if (x == 0) {
            s[i] = '(';
            if (s[i + 1] == '(') x += 2;
        } else if (s[i + 1] == '(') {
            s[i] = ')';
        } else if (x == 2) {
            s[i] = ')';
            x -= 2;
        } else {
            s[i] = '(';
        }
    }


    debug(s);
    int ans = 0;

    vector<int> st;

    for (int i = 0; i < n;i++) {
        if (s[i] == ')') {
            ans += i - st.back();
            st.pop_back();
        } else {
            st.push_back(i);
        }
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
