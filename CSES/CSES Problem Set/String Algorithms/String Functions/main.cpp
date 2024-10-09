// ﷽
// https://cses.fi/problemset/task/2107

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

vector<int> zfunction(string s) {
    int n = s.size();

    vector<int> z(n);
    for (int i = 1, l = 1, r = 1; i < n; i++) {
        if (i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) r = i + z[i], l = i;
    }

    return z;
}

vector<int> KMP(const string &a) {
    // search for b in a
    vector<int> ans;
    int n = a.length();
    vi b_table(n);
    b_table[0] = 0;

    for (int i = 1, k = 0; i < n; i++) {
        while (k > 0 && a[k] != a[i])
            k = b_table[k - 1];
        k += a[i] == a[k];
        b_table[i] = k;
    }

    return b_table;
}

void solve() {
    string s;
    cin >> s;

    auto a = zfunction(s), b = KMP(s);
    debug(a);
    debug(b);

    for (int i = 0; i < sz(s); i++) {
        cout << a[i] << " \n"[i == sz(s) - 1];
    }
    for (int i = 0; i < sz(s); i++) {
        cout << b[i] << " \n"[i == sz(s) - 1];
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    /*cin >> T;*/
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
